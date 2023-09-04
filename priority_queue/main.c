#include <stdlib.h>
#include <stdio.h>

#include "priority_queue.h"

#define QUEUE_SIZE 8

int cmpelem(elem_t x, elem_t y)
{
	return x - y;
}

int main(void)
{
	pq_t pq;
	int i;
	elem_t x;
	
	create_prio_queue(&pq, QUEUE_SIZE);

	elem_t elements[] = {71, 74, 2, 72, 54, 93, 52, 28};

	for (i = 0; i < QUEUE_SIZE; i ++)
	{
		append_pq(&pq, elements[i], cmpelem);
	}

	for (i = 0; i < QUEUE_SIZE; i ++)
	{
		serve(&pq, &x, cmpelem);
		printf("%d\n", x);
	}

	destroy_prio_queue(&pq);
}
