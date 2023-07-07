#include <stdlib.h>
#include <stdio.h>

#include "single_list.h"

/*
	初始化
	构造一个空的单链表
*/
status_t single_list_init(sgl_t *list)
{
	list->first = NULL;
	list->len = 0;
	return OK;
}

/*
	单链表查找操作
	找到链表内i处的元素，并通过指针x返回
	返回值：
	如果查找成功，返回OK，如越界，返回ERROR
*/
status_t single_list_find(sgl_t *list, int i, elem_t *x)
{
	if (i < 0 || i > list->len-1)
		return ERROR;
	
	sgln_t *p = list->first;
	int j;
	for (j = 0; j < i; j ++)
		p = p->link; // 从头结点开始查找
	
	*x = p->element;

	return OK;
}

/*
	单链表插入
	在链表的i位置处插入元素x
	返回值：
	成功返回OK，否则返回ERROR	
*/
status_t single_list_insert(sgl_t *list, int i, elem_t x)
{
	sgln_t *p, *q;
	int j;

	if (i < 0 || i > list->len)
		return ERROR;
	
	if (!buy_node(&q, x))
		return ERROR;

	if (!i)
	{
		q->link = list->first;
		list->first = q;
	}
	else
	{
		p = list->first;
		for (j = 1; j < i; j ++)
			p = p->link;
		
		q->link = p->link;
		p->link = q;
	}

	list->len ++;
	return OK;
}

/*
	单链表删除
	删除链表中i位置处的元素
	返回值：成功返回OK，否则返回ERROR
*/
status_t single_list_delete(sgl_t *list, int i)
{
	if (i < 0 || i >= list->len)
		return ERROR;

	sgln_t *p, *q = list->first;
	int j;
	for (j = 0; j < i; j ++)
	{
		p = q;
		q = q->link;
	}

	if (!i)
		list->first = q->link;
	else
		p->link = q->link;

	ret_node(q);
	list->len --;
	
	return OK;
}

/*
	单链表的输出
*/
void single_list_output(sgl_t *list)
{
	if (list->len <= 0)
	{
		printf("single list{}\n");
		return;
	}

	printf("single list{");

	sgln_t *p = list->first;
	int i = 0;
	while (i ++ < list->len-1)
	{
		printf("%d, ", p->element);
		p = p->link;
	}

	printf("%d}\n", p->element);
}

/*
	单链表的撤销
	释放单链表所用的动态分配的内存空间，以防止内存泄漏
*/
void single_list_destroy(sgl_t *list)
{
	sgln_t *p;
	while (list->first != NULL)
	{
		p = list->first;
		list->first = p->link;

		ret_node(p);
	}

	list->len = 0;
}

/*
	单链表的清空
*/
void single_list_clear(sgl_t *list)
{
	single_list_destroy(list);
}

/*
	单链表长度
	返回单链表长度
*/
int single_list_length(sgl_t list)
{
	return list.len;	
}

/*
	判断单链表是否为空
*/
int single_list_is_empty(sgl_t list)
{
	return list.len <= 0;
}

/*
	单链表跟新
	更新链表内i位置处的元素值，如成功，返回OK，越界返回ERROR
*/
status_t single_list_update(sgl_t *list, int i, elem_t x)
{
	if (i < 0 || i >= list->len)
		return ERROR;

	sgln_t *p = list->first;
	int j;
	for (j = 0; j < i; j ++)
		p = p->link;
	p->element = x;

	return OK;
}

/*
	链表排序
	对传入链表内的结点按其元素值进行升序排序
*/
void single_list_sort(sgl_t *list)
{
	if (list->len <= 1)
		return;

	sgln_t *p = list->first->link;
	sgln_t *q = p->link;

	list->first->link = NULL;
	list->len = 1;

	while (p != NULL)
	{
		q = p->link;
		p->link = NULL;
		insert_by_order(list, p);
		p = q;
	}
}

/*
	将新的结点插入到链表中, 并保持链表原来的顺序
*/
static void insert_by_order(sgl_t *list, sgln_t *n)
{
	if (n->element < list->first->element)
	{
		n->link = list->first;
		list->first = n;
		list->len ++;
		return;
	}

	sgln_t *p = list->first;
	sgln_t *q = p->link;

	while (q != NULL && q->element > n->element)
	{
		p = q;
		q = p->link;
	}
	
	n->link = p->link;
	p->link = n;

	list->len ++;
}

/*
	创建结点
	在堆上开辟一块结点空间，并通过ptr返回其地址
	返回值：
	成功返回OK，否则返回ERROR
*/
static status_t buy_node(sgln_t **ptr, elem_t val)
{
	sgln_t *n = malloc(sizeof(sgln_t));
	if (n == NULL)
		return ERROR;
	
	n->element = val;
	n->link = NULL;
	
	*ptr = n;
	return OK;
}

/*
	归还结点
	释放结点所占的内存空间，并将ptr的值置为NULL
*/
static void ret_node(sgln_t *ptr)
{
	free(ptr);
	ptr = NULL;
}

