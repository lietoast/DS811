#ifndef _MIN_HEAP_H__
#define _MIN_HEAP_H__

typedef int prio_t;

typedef struct heap_node
{
	prio_t priority;
	void *data;
}hpnode_t;

static void adjust_down(hpnode_t heap[], int current, int border);

void create_heap(hpnode_t heap[], int n);

#endif
