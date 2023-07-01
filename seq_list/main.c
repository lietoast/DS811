#include <stdlib.h>
#include <stdio.h>

#include "seq_list.h"

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

	sqlist_t list;
	seq_list_init(&list);

	int select = 1;
	while (select)
	{
		select = 0;
		printf("Please select: ");
		scanf("%d", &select);

		int index;
		elem_t data;

		switch (select)
		{
		case 1:
			if(seq_list_is_empty(list))
				printf("Empty\n");
			else
				printf("Not empty\n");
			break;
		case 2:
			printf("Length of seq list is: %d\n", seq_list_length(list));
			break;
		case 3:
			printf("Please input an index: ");
			scanf("%d", &index);
			if (seq_list_find(list, index, &data) == ERROR)
			{
				fprintf(stderr, "index %d out of bound [0, %d)\n", index, seq_list_length(list));
				break;
			}
			printf("list[%d] -> %d\n", index, data);
			break;
		case 4:
			printf("Please input an index: ");
			scanf("%d", &index);
			printf("Please input data: ");
			scanf("%d", &data);
			if (OK == seq_list_insert(&list, index, data))
				break;
			fprintf(stderr, "index %d out of bound [0, %d]\n", index, seq_list_length(list));
			break;
		case 5: // delete
			printf("Please input an index: ");
			scanf("%d", &index);
			if (seq_list_delete(&list, index) == ERROR)
				fprintf(stderr, "index %d out of bound [0, %d)\n", index, seq_list_length(list));
			break;
		case 6: // update
			printf("Please input an index: ");
			scanf("%d", &index);
			printf("Please input modified data: ");
			scanf("%d", &data);
			if (ERROR == seq_list_update(&list, index, data))
				fprintf(stderr, "index %d out of bound [0, %d)\n", index, seq_list_length(list));
			break;
		case 7: // output
			seq_list_output(list);
			break;
		case 8: // sort
			seq_list_sort(&list);
			break;
		case 9: // clear
			seq_list_clear(&list);
			break;
		case 0:
			break;
		default:
			printf("Illegal input!");
			break;
		}
	}

	seq_list_destroy(&list);

	exit(0);
}
