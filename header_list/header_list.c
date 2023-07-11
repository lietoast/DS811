#include <stdlib.h>
#include <stdio.h>

#include "header_list.h"


/*
	初始化
	构造一个仅带有表头结点的空的单链表
	返回值：
	如果成功，返回OK，否则返回ERROR
*/
status_t header_list_init(hdlist_t *list)
{
	list->head = malloc(sizeof(sgln_t));

	if (list->head == NULL)
		return ERROR;
	
	list->head->link = NULL;
	list->len = 0;
	
	return OK;
}

/*
	插入
	插入元素时不需要单独处理插入头结点之前的情况
*/
status_t header_list_insert(hdlist_t *list, int i, elem_t x)
{
	if (i < 0 || i > list->len)
		return ERROR;
	
	sgln_t *p = list->head;
	int j;
	for (j = 0; j < i; j ++)
		p = p->link;
	
	sgln_t *n = buy_node(x);
	if (n == NULL)
		return ERROR;

	n->link = p->link;
	p->link = n;
	list->len ++;

	return OK;
}

/*
	删除结点
*/
status_t header_list_delete(hdlist_t *list, int i)
{
	if (i < 0 || i >= list->len)
		return ERROR;

	sgln_t *p = list->head;
	int j;
	for (j = 0; j < i; j ++)
		p = p->link;
	
	sgln_t *q = p->link;
	p->link = q->link;
	ret_node(q);
	list->len --;

	return OK;
}

static sgln_t *buy_node(elem_t val)
{
	sgln_t *n = malloc(sizeof(sgln_t));
	if (n == NULL)
		return NULL;
	
	n->element = val;
	n->link = NULL;

	return n;
}

static void ret_node(sgln_t *node)
{
	free(node);
}
