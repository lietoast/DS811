#ifndef _POSTFIX_EXPR_H__
#define _POSTFIX_EXPR_H__

#include <stdbool.h>

#include "stack.h"

#define ITEM_SIZE 50

/*
	判断表达式中是否包含非法字符，合法字符仅包含0~9、.、+、-、*、^、/和空格
*/
bool is_legal(char *postfix);

/*
	从表达式的当前位置cur_pos获取一个元素，获取完成后，cur_pos移动到下一个元素的首字母位置
	出现异常返回-1；若当前元素为操作数则返回0，若为操作符，返回-1
*/
int get_item(char *postfix, int *cur_pos, char *item);

/*
	根据操作符执行由2个操作数和一个操作符构成的基础表达式的计算
*/
status_t do_operator(stk_t *s, char oper);

/*
	对后缀表达式postfix进行求值
*/
double cal_postfix_expr(char *postfix);

#endif
