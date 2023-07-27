#ifndef _STACK_H__
#define _STACK_H__

#include <stdlib.h>
#include <stdbool.h>

#include "seq_list.h"

// 堆栈类型定义
typedef struct stack
{
	int top;              // 栈顶元素位置
	sqlist_t *collection; // 元素列表
}stk_t;

/*
	栈的初始化
	创建一个默认大小容量的空栈
	返回值：
	如成功，返回OK，否则返回ERROR
*/
status_t stack_create(stk_t *s);

/*
	销毁栈，并释放其所占用的内存空间
*/
void stack_destroy(stk_t *s);

/*
	检查栈是否为空
	返回值：
	如果为空，返回true，否则返回false
*/
bool stack_is_empty(stk_t s);

/*
	获取栈顶元素，并通过x返回
	返回值：
	如果栈内没有元素，返回ERROR，否则返回OK
*/
status_t stack_top(stk_t s, elem_t *x);

/*
	在栈顶位置插入元素x（入栈操作）
*/
void push(stk_t *s, elem_t x);

/*
	删除栈顶元素（出栈操作）并将删除掉的元素通过x返回
	返回值：
	如果栈内没有元素，返回ERROR，否则返回OK
*/
status_t pop(stk_t *s, elem_t *x);

/*
	清除栈中所有元素
*/
void stack_clear(stk_t *s);

#endif
