#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

int main(void)
{
	stk_t stack;
	if (stack_create(&stack) != OK)
		exit(-1);

	int choice = 1;
	while (choice)
	{
		choice = 0;
		
		printf("***************************\n");
		printf("* [1] is empty  [2] top   *\n");
		printf("* [3] push      [4] pop   *\n");
		printf("* [5] clear     [0] quit  *\n");
		printf("***************************\n");
		printf("Please select: ");
		scanf("%d", &choice);

		elem_t x;
		
		switch (choice)
		{
		case 1:
			if (stack_is_empty(stack))
				printf("Empty\n");
			else
				printf("Not empty\n");
			break;
		case 2:
			if (stack_top(stack, &x) != OK)
				fprintf(stderr, "stack is empty, top func not available\n");
			else
				printf("Element: %d\n", x);
			break;
		case 3:
			printf("Input number of elements you would like to enter: ");
			int num;
			if (scanf("%d", &num), num <= 0)
				break;
			printf("Input %d elements:\n", num);
			while (num > 0)
			{
				scanf("%d", &x);
				push(&stack, x);
				num --;
			}
			fflush(stdin);
			break;
		case 4:
			if (pop(&stack, &x) != OK)
				fprintf(stderr, "stack is empty, pop func not available\n");
			else
				printf("%d has been popped out\n", x);
			break;
		case 5:
			stack_clear(&stack);
			break;
		case 0:
			break;
		default:
			printf("Illegal input!\n");
			break;	
		}
	}

	stack_destroy(&stack);

	exit(0);
}
