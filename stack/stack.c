#include "stack.h"

/*
	栈的初始化
	创建一个默认大小容量的空栈
	返回值：
	如成功，返回OK，否则返回ERROR
*/
status_t stack_create(stk_t *s)
{
	// 创建放置栈内元素的容器
	sqlist_t *colle = malloc(sizeof(sqlist_t));
	if (colle == NULL)
		return ERROR;
	status_t flag = seq_list_init(colle);
	if (flag != OK)
		return flag;
	
	s->top = -1;
	s->collection = colle;
	
	return OK;
}

/*
	销毁栈，并释放其所占用的内存空间
*/
void stack_destroy(stk_t *s)
{
	// 销毁放置元素的容器
	seq_list_destroy(s->collection);
	// 释放容器变量所占空间
	free(s->collection);

	// 防止再次访问已被释放的内存空间
	s->collection = NULL;
	s->top = -1;
}

/*
	检查栈是否为空
	返回值：
	如果为空，返回true，否则返回false
*/
bool stack_is_empty(stk_t s)
{
	return s.top < 0;
}

/*
	获取栈顶元素，并通过x返回
	返回值：
	如果栈内没有元素，返回ERROR，否则返回OK
*/
status_t stack_top(stk_t s, elem_t *x)
{
	return seq_list_find(*(s.collection), s.top, x);
}

/*
	在栈顶位置插入元素x（入栈操作）
*/
void push(stk_t *s, elem_t x)
{
	s->top ++;
	seq_list_insert(s->collection, s->top, x);
}

/*
	删除栈顶元素（出栈操作）并将删除掉的元素通过x返回
	返回值：
	如果栈内没有元素，返回ERROR，否则返回OK
*/
status_t pop(stk_t *s, elem_t *x)
{
	status_t flag = stack_top(*s, x);
	if (flag != OK)
		return flag;

	seq_list_delete(s->collection, s->top--);
	
	return OK;
}

/*
	清除栈中所有元素
*/
void stack_clear(stk_t *s)
{
	seq_list_clear(s->collection);
	s->top = -1;
}



