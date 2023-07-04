#include <stdlib.h>
#include <stdio.h>

#include "single_list.h"

int main(void)
{
	// 线性表ADT
    // 数据:
    // 零个或多个数据元素构成的线形序列(a0, a1, ..., an-1)
    // 数据间的关系为一对一
    // 运算:
    // init, destroy
    printf("******************************\n");
    printf("* [1] is empty  [2] length   *\n");
    printf("* [3] find      [4] insert   *\n");
    printf("* [5] delete    [6] update   *\n");
    printf("* [7] output    [8] sort     *\n");
    printf("* [9] clear     [0] quit     *\n");
    printf("******************************\n");

	sgl_t list;
	single_list_init(&list);

	int select = 1;
	while (select)
	{
		select = 0;
		printf("Please select: ");
		scanf("%d", &select);

		int index = -1;
		elem_t element = (elem_t)0;

		switch (select)
		{
		case 1:
			if (single_list_is_empty(list))
				printf("Empty\n");
			else
				printf("Not empty\n");
			break;
		case 2:
			printf("Length of the single list: %d\n", single_list_length(list));
			break;
		case 3:
			printf("Please input an index: ");
			scanf("%d", &index);
			if (single_list_find(&list, index, &element) == OK)
			{
				printf("list[%d] -> %d\n", index, element);
				break;
			}
			fprintf(stderr, "index %d out of bound [0, %d)\n", index, single_list_length(list));
			break;
		case 4:
			printf("Please input <index,elements>(s) (end with <-1, -1>): ");
			while (scanf("%d,%d", &index, &element), index != -1)
				if (single_list_insert(&list, index, element) != OK)
					fprintf(stderr, "index %d out of bound [0, %d]\n", index, single_list_length(list));
			break;
		case 5:
			printf("Please input an index: ");
			scanf("%d", &index);
			if (single_list_delete(&list, index) != OK)
				fprintf(stderr, "index %d out of bound [0, %d)\n", index, single_list_length(list));
			break;
		case 6:
			printf("Please input an index: ");
			scanf("%d", &index);
			printf("Please input data: ");
			scanf("%d", &element);
			if (single_list_update(&list, index, element) == ERROR)
				fprintf(stderr, "index %d out of bound [0,%d)\n", index, single_list_length(list));
			break;
		case 7:
			single_list_output(&list);
			break;
		case 0:
			break;
		default:
			printf("Illegal input!\n");
		}
	}

	single_list_destroy(&list);

	exit(0);
}


