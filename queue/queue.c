#include <stdlib.h>

#include "queue.h"

/*
	创建一个容量为capacity的队列
*/
void queue_create(queue_t *q, int capacity)
{
	if (capacity <= 0)
		return;
	
	q->front = q->rear = 0;
	q->cap = capacity;
	q->elements = malloc(capacity * sizeof(elem_t));
}

/*
	销毁一个已存在的队列，释放其所占的内存空间
*/
void queue_destroy(queue_t *q)
{
	q->front = q->rear = 0;
	q->cap = 0;
	free(q->elements);
	q->elements = NULL;
}

/*
	判断队列是否为空
	返回值：
	若是，返回true，否则返回false
*/
bool queue_empty(queue_t q)
{
	return q.front == q.rear;
}

/*
	判断队列是否已满
	返回值：
	若是，返回true，否则返回false
*/
bool queue_full(queue_t q)
{
	return (q.rear+1)%q.cap == q.front;
}

/*
	获取队头元素，并通过x返回
	返回值：
	若队列为空，返回ERROR，否则返回OK
*/
status_t queue_front(queue_t *q, elem_t *x)
{
	if (queue_empty(*q))
		return ERROR;
	
	*x = q->elements[q->front];
	return OK;
}

/*
	入队操作，将元素x入队
	返回值：
	若队列已满，返回ERROR，否则返回OK
*/
status_t enqueue(queue_t *q, elem_t x)
{
	if (queue_full(*q))
		return ERROR;
	
	q->elements[q->rear] = x;
	q->rear = (q->rear+1)%q->cap;

	return OK;
}

/*
	出队操作，出队元素通过x返回
	返回值：
	若队列为空，返回ERROR，否则返回OK
*/
status_t dequeue(queue_t *q, elem_t *x)
{
	if (queue_empty(*q))
		return ERROR;
	
	*x = q->elements[q->front];
	q->front = (q->front + 1) % q->cap;

	return OK;
}

/*
	清空队列内的元素
*/
void queue_clear(queue_t *q)
{
	q->front = q->rear = 0;
}
