#include <stdlib.h>

#include "priority_queue.h"

static void adjust_up(elem_t heap[], int current, int (*cmpelem)(elem_t, elem_t))
{
	int p = current;
	elem_t temp;

	while (p > 0)
	{
		if (cmpelem(heap[p], heap[(p-1)>>1]) < 0) // 若p指向的结点小于其双亲结点, 则调整位置
		{
			temp = heap[p];
			heap[p] = heap[(p-1)>>1];
			heap[(p-1)>>1] = temp;

			p = (p-1) >> 1;
		}
		else
			break;
	}
}

static void adjust_down(elem_t heap[], int current, int border, int (*cmpelem)(elem_t, elem_t))
{
	int p = current;
	int min_child, lchild;
	elem_t temp;

	while ((lchild = (p<<1)+1) < border)
	{
		if (lchild + 1 < border && cmpelem(heap[lchild+1], heap[lchild]) <= 0)
			min_child = lchild + 1;
		else
			min_child = lchild;

		if (cmpelem(heap[p], heap[min_child]) <= 0)
			break;
		else
		{
			temp = heap[p];
			heap[p] = heap[min_child];
			heap[min_child] = temp;
			
			p = min_child;
		}
	}
}

void create_prio_queue(pq_t *pq, size_t max_size)
{
	pq->elements = malloc(max_size * sizeof(elem_t));
	if (pq->elements == NULL)
	{
		return;
	}

	pq->n = 0;
	pq->max_size = max_size;
}

void destroy_prio_queue(pq_t *pq)
{
	pq->n = 0;
	pq->max_size = 0;
	free(pq->elements);
	pq->elements = NULL;
}

bool ispqempty(pq_t pq)
{
	return pq.n == 0;
}

bool ispqfull(pq_t pq)
{
	return pq.n == pq.max_size;
}

size_t pqsize(pq_t pq)
{
	return pq.n;
}

size_t append_pq(pq_t *pq, elem_t elem, int (*cmpelem)(elem_t, elem_t))
{
	if (ispqfull(*pq))
		return pqsize(*pq);

	pq->elements[pq->n++] = elem;
	adjust_up(pq->elements, pq->n - 1, cmpelem);

	return pq->n;
}

size_t serve(pq_t *pq, elem_t *x, int (*cmpelem)(elem_t, elem_t))
{
	if (ispqempty(*pq))
		return pqsize(*pq);

	*x = pq->elements[0];
	pq->n --;
	pq->elements[0] = pq->elements[pq->n];
	adjust_down(pq->elements, 0, pq->n-1, cmpelem);

	return pq->n;
}
