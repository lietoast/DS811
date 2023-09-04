#include <stdlib.h>
#include <stdio.h>

#include "min_heap.h"

#define NUM_NODE 8

int main(void)
{
	int i;
	hpnode_t *heap = malloc(NUM_NODE * sizeof(hpnode_t));
	if (heap == NULL)
	{
		perror("malloc()");
		exit(1);
	}
	
	int priorities[] = {61, 28, 81, 43, 36, 47, 83, 5};
	for (i = 0; i < NUM_NODE; i ++)
		heap[i].priority = priorities[i];

	create_heap(heap, NUM_NODE);

	for (i = 0; i < NUM_NODE; i ++)
		printf("%d\n", heap[i].priority);
	
	exit(0);
}
