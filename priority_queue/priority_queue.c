#include <stdlib.h>

#include "priority_queue.h"

static void adjust_up(elem_t heap[], int current, void (*cmpelem)(elem_t, elem_t))
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

void create_prio_queue(pq_t *pq, size_t max_size);

void destroy_prio_queue(pq_t *pq);

bool ispqempty(pq_t pq);

bool ispqfull(pq_t pq);

size_t pqsize(pq_t pq);

size_t append_qp(pq_t *pq, elem_t elem);

size_t serve(pq_t *pq, elem_t *x);
