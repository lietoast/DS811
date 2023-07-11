#include <stdlib.h>
#include <stdio.h>

#include "header_list.h"

void show_list(hdlist_t *list);

int main(void)
{
	hdlist_t list;
	header_list_init(&list);

	int i;
	for (i = 0; i < 10; i ++)
	{
		header_list_insert(&list, i, (elem_t)i);
	}
	show_list(&list);

	for (i = 0; i < 5; i ++)
	{
		header_list_delete(&list, 0);
	}
	show_list(&list);

	exit(0);
}

void show_list(hdlist_t *list)
{
	sgln_t *p = list->head;

	int i = 0;
	while (p->link != NULL)
	{
		p = p->link;
		printf("list[%d] = %d\n", i++, p->element);
	}
}
