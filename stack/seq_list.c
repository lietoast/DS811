#include <stdlib.h>
#include <stdio.h>

#include "seq_list.h"

#define DEFAULT_CAPACITY 10

status_t seq_list_init(sqlist_t *list)
{
	list->cap = DEFAULT_CAPACITY;
	list->len = 0;
	list->elements = malloc(DEFAULT_CAPACITY * sizeof(elem_t));

	if (!list->elements)
		return ERROR;
	return OK;	
}

// 顺序表查找
status_t seq_list_find(sqlist_t list, int i, elem_t *x)
{
	if (i < 0 || i > list.len-1) // 查看下标是否越界
		return ERROR;

	*x = list.elements[i]; // 取出下标为i的元素的值通过x返回
	return OK;
}

// 返回顺序表的长度
int seq_list_length(sqlist_t list)
{
	return list.len;
}

// 顺序表插入元素
status_t seq_list_insert(sqlist_t *list, int i, elem_t x)
{
	if (i < 0 || i > seq_list_length(*list))
		return ERROR;
	if (seq_list_length(*list) >= list->cap)
		seq_list_incr_capacity(list);
	
	int j;
	for (j = list->len; j > i; j --)
		list->elements[j] = list->elements[j-1];
	list->len ++;
	list->elements[i] = x;
	
	return OK;
}


// 顺序表扩容
static void seq_list_incr_capacity(sqlist_t *list)
{
	// 决定扩容因子大小
	double incr_factor;
	if (list->cap <= 500)
		incr_factor = 2.0;
	else if (list->cap <= 2000)
		incr_factor = 1.5;
	else
		incr_factor = 1.25;
	list->cap = (int)(list->cap * incr_factor);
	list->elements = realloc(list->elements, list->cap * sizeof(elem_t));
}

// 查看顺序表是否为空
int seq_list_is_empty(sqlist_t list)
{
	return list.len <= 0;
}

// 顺序表元素删除
status_t seq_list_delete(sqlist_t *list, int i)
{
	if (i < 0 || i >= list->len)
		return ERROR;

	int j;
	for (j = i+1; j < list->len-1; j ++)
		list->elements[j] = list->elements[j+1];
	
	list->len --;

	if (list->cap > DEFAULT_CAPACITY && list->len <= (list->cap >> 1))
		seq_list_decr_capacity(list);

	return OK;	
}

// 元素表缩容
static void seq_list_decr_capacity(sqlist_t * list)
{
	list->cap -= list->cap >> 2;

	list->elements = realloc(list->elements, list->cap * sizeof(elem_t));
}

// 顺序表更新
status_t seq_list_update(sqlist_t *list, int i, elem_t x)
{
	if (i < 0 || i >= list->len)
		return ERROR;
	
	list->elements[i] = x;
	return OK;
}

// 顺序表排序
void seq_list_sort(sqlist_t *list, int (*cmpelem)(const void *, const void *))
{
	if (list->len < 2)
		return;

	mergesort(list->elements, list->len, sizeof(elem_t), cmpelem);
}

// 顺序表清除
void seq_list_clear(sqlist_t *list)
{
	list->len = 0;
	list->cap = DEFAULT_CAPACITY;
	free(list->elements);
	list->elements = malloc(DEFAULT_CAPACITY + sizeof(elem_t));
}

// 顺序表的撤销
void seq_list_destroy(sqlist_t *list)
{
	free(list->elements);

	list->elements = NULL;
	list->cap = list->len = 0;
}

// 顺序表逆置
void seq_list_reverse(sqlist_t *list)
{
	int h = 0, t = list->len-1;
	while (h > t)
	{
		elem_t tmp = list->elements[h];
		list->elements[h] = list->elements[t];
		list->elements[t] = tmp;
	}
}



