#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

const int N = 15;

int main(void)
{
	queue_t queue;
	queue_create(&queue, N);

	int choice = 1;
	while (choice)
	{
		choice = 0;
		printf("*****************************\n");
		printf("* [1] is empty  [2] is full *\n");
		printf("* [3] first ele [4] enqueue *\n");
		printf("* [5] dequeue   [6] clear   *\n");
		printf("* [0] quit                  *\n");
		printf("*****************************\n");
		printf("Please select: ");
		scanf("%d", &choice);

		elem_t data;

		switch (choice)
		{
		case 1:
			if (queue_empty(queue))
				printf("Empty\n");
			else
				printf("Not empty\n");
			break;
		case 2:
			if (queue_full(queue))
				printf("Full\n");
			else
				printf("Not full\n");
			break;
		case 3:
			if (queue_front(&queue, &data) != OK)
				fprintf(stderr, "the queue is empty now, first ele func not available\n");
			else
				printf("The first element is: %d\n", data);
			break;
		case 4:
			printf("Please input number of elements you would like to enter: ");
			int num;
			if (scanf("%d", &num), num > 0)
				printf("Please input %d elements:\n", num);
			else
				break;
			while (num -- > 0)
			{
				scanf("%d", &data);
				if (enqueue(&queue, data) != OK)
					break;
			}
			fflush(stdin);
			break;
		case 5:
			if (dequeue(&queue, &data) != OK)
				fprintf(stderr, "the queue is empty now, dequeue func not available\n");
			else
				printf("%d has been removed\n", data);
			break;
		case 6:
			queue_clear(&queue);
			break;
		case 0:
			break;
		default:
			printf("Illegal input!\n");
			break;
		}
	}

	queue_destroy(&queue);
	
	exit(0);
}
