#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

int main(void)
{
	lklist_t list;
	list_init(&list);

	printf("1. Is empty: %d\n", list_is_empty(&list));
	printf("2. Length: %lu\n", list_length(&list));

	int i, j;
	for (j = 0; j < 2; j ++)
	{
		for (i = 0; i < 10; i ++)
		{
			list_insert(&list, (size_t)(i/2), (elem_t)i);
			printf("%d. Insert %d into list[%d], ", 3+i+j*11, i, (i/2));
			list_output(&list);
		}
		if (!j)
		{
			list_clear(&list);
			printf("13. Clear, ");
			list_output(&list);
		}
	}

	for (i = 0; i < 5; i ++)
	{
		list_delete(&list, (size_t)(i>>1));
		printf("%d. Delete list[%d], ", 24+i, i>>1);
		list_output(&list);
	}

	printf("29. Length: %lu\n", list_length(&list));

	list_update(&list, (size_t)2, 1000);
	printf("30. Update: set list[%d]=%d\n", 2, 1000);
	list_output(&list);

	list_destroy(&list);

	exit(0);
}
