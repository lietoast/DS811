#ifndef _PRIORITY_QUEUE_H__
#define _PRIORITY_QUEUE_H__

#include <stdbool.h>

typedef int elem_t;

// 数据: n(n >= 0)个元素的最小堆
typedef struct priority_queue
{
	elem_t *elements; // 存储元素的数组
	size_t n;         // 优先队列中元素的数量
	size_t max_size;  // 优先队列的容量
}pq_t;

void create_prio_queue(pq_t *pq, size_t max_size);

void destroy_prio_queue(pq_t *pq);

bool ispqempty(pq_t pq);

bool ispqfull(pq_t pq);

size_t pqsize(pq_t pq);

size_t append_pq(pq_t *pq, elem_t elem, int (*cmpelem)(elem_t, elem_t));

size_t serve(pq_t *pq, elem_t *x, int (*cmpelem)(elem_t, elem_t));

#endif
