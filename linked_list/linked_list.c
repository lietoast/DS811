#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

// 初始化链表
// 初始化完成后，链表内仅含一个头结点，其长度为0
// 返回值：
// 如成功，返回OK，如内存空间不足，返回ERROR
status_t list_init(lklist_t *list)
{
	status_t st = buy_node(&list->first, 0);
	if (st != OK)
		return st;

	list->last = list->first;
	list->first->rlink = list->first->llink = list->first;
	list->len = (size_t)0;

	return OK;
}

// 向链表内i位置处插入数据x
// 返回值：
// 如成功，返回OK；否则返回ERROR
status_t list_insert(lklist_t *list, size_t i, elem_t x)
{
	if (i < 0 || i > list->len)
		return ERROR;

	lklnode_t *n = NULL;
	status_t st = buy_node(&n, x);
	if (st != OK)
		return st;

	lklnode_t *p = list->first;
	while (i-- > 0)
		p = p->rlink;

	n->rlink = p->rlink;
	n->llink = p;
	p->rlink->llink = n;
	p->rlink = n;
	
	if (list->len <= 0)
		list->last = n;
	
	list->len ++;

	return OK;
}

// 删除链表内i位置处元素
// 返回值：
// 如成功，返回OK，越界返回ERROR
status_t list_delete(lklist_t *list, size_t i)
{
	if (i < 0 || i >= list->len)
		return ERROR;
	
	lklnode_t *p = list->first->rlink;
	while (i-- > 0)
		p -> p->rlink;

	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	if (list->last == p)
		list->last = p->llink;
	list->len --;

	ret_node(p);

	return OK;
}

// 创建新的链表结点
static status_t buy_node(lklnode_t **ptr, elem_t val)
{
	*ptr = malloc(sizeof(lklnode_t));
	if (*ptr == NULL)
		return ERROR;

	(*ptr)->llink = NULL;
	(*ptr)->rlink = NULL;
	(*ptr)->element = val;

	return OK;
}

// 销毁链表的结点
static void ret_node(lklnode_t *n)
{
	free(n);
}

