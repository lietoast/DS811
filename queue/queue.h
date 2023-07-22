#ifndef _QUEUE_H__
#define _QUEUE_H__

#include <stdbool.h>

#ifndef DS_811_STATUS__
#define ERROR       0 // 出现错误
#define OK          1 // 运行通过
#define OVERFLOW    2 // 上溢
#define UNDERFLOW   3 // 下溢
#define NOT_PRESENT 4 // 元素不存在
#define DUPLICATE   5 // 有重复元素
typedef int status_t;
#endif

typedef int elem_t;

typedef struct queue
{
	int front;
	int rear;
	int cap;
	elem_t *elements;
}queue_t;

/*
	创建一个容量为capacity的队列
*/
void queue_create(queue_t *q, int capacity);

/*
	销毁一个已存在的队列，释放其所占的内存空间
*/
void queue_destroy(queue_t *q);

/*
	判断队列是否为空
	返回值：
	若是，返回true，否则返回false
*/
bool queue_empty(queue_t q);

/*
	判断队列是否已满
	返回值：
	若是，返回true，否则返回false
*/
bool queue_full(queue_t q);

/*
	获取队头元素，并通过x返回
	返回值：
	若队列为空，返回ERROR，否则返回OK
*/
status_t queue_front(queue_t *q, elem_t *x);

/*
	入队操作，将元素x入队
	返回值：
	若队列已满，返回ERROR，否则返回OK
*/
status_t enqueue(queue_t *q, elem_t x);

/*
	出队操作，出队元素通过x返回
	返回值：
	若队列为空，返回ERROR，否则返回OK
*/
status_t dequeue(queue_t *q, elem_t *x);

/*
	清空队列内的元素
*/
void queue_clear(queue_t *q);

#endif
