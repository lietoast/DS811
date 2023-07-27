#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "postfix_expr.h"

/*
	判断表达式中是否包含非法字符，合法字符仅包含0~9、.、+、-、*、^、/和空格
*/
bool is_legal(char *postfix)
{
	int i;
	char c;
	for (i = 0; i < strlen(postfix); i ++)
	{
		c = postfix[i];
		if (!((c >= '0' && c <= '9') || c == '.' || c == '+' || c == '-' 
			|| c == '*' || c == '^' || c == '/' || c == ' '))
			return false;
	}
	return true;
}

/*
	从表达式的当前位置cur_pos获取一个元素，获取完成后，cur_pos移动到下一个元素的首字母位置
	出现异常返回-1；若当前元素为操作数则返回0，若为操作符，返回-1
*/
int get_item(char *postfix, int *cur_pos, char *item)
{
	int i = 0, k = *cur_pos, flag;
	if (postfix[k] == '.') // 元素的首字符不能是小数点
		flag = -1;
	else if (postfix[k] >= '0' && postfix[k] <= '9') // 元素为操作数
	{
		while ((postfix[k] >= '0' && postfix[k] <= '9') || postfix[i] == '.')
			item[i ++] = postfix[k ++];
		item[i] = '\0';
		flag = 0;
	}
	else // 元素为操作符
	{
		item[0] = postfix[k ++];
		item[1] = '\0';
		flag = 1;
	}

	while (postfix[k] == ' ') // 跳过当前空格，将当前位置制动到下一个元素的首字符处
		k ++;

	*cur_pos = k;
	return flag;
}

/*
	根据操作符执行由2个操作数和一个操作符构成的基础表达式的计算
*/
status_t do_operator(stk_t *s, char oper)
{
	double oper1, oper2;
	if (pop(s, &oper2) != OK || pop(s, &oper1) != OK)
		return ERROR;
	
	switch (oper)
	{
	case '+':
		push(s, oper1 + oper2);
		break;
	case '-':
		push(s, oper1 - oper2);
		break;
	case '*':
		push(s, oper1 * oper2);
		break;
	case '/':
		if (!oper2)
			return ERROR;
		push(s, oper1 / oper2);
		break;
	case '^':
		push(s, pow(oper1, oper2));
		break;
	}

	return OK;
}

/*
	对后缀表达式postfix进行求值
*/
double cal_postfix_expr(char *postfix)
{
	stk_t s;
	char item[ITEM_SIZE];
	double data;
	int flag = -1;
	int cur_pos = 0;

	while (postfix[cur_pos] == ' ') // 过滤后缀表达式最前面的所有空格
		cur_pos ++;
	
	if (stack_create(&s) != OK)
	{
		fprintf(stderr, "failed to alloc mem space to stack\n");
		exit(-1);
	}

	while (cur_pos < strlen(postfix))
	{
		flag = get_item(postfix, &cur_pos, item);
		if (flag == -1)
		{
			fprintf(stderr, "illegal element\n");
			exit(-1);
		}
		else if (flag == 1)
		{
			switch (item[0])
			{
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
					do_operator(&s, item[0]);
					break;
			}
		}
		else
		{
			data = atof(item);
			push(&s, data);
		}
	}

	pop(&s, &data);
	if (!stack_is_empty(s))
	{
		fprintf(stderr, "illegal expr: %s\n", postfix);
		exit(-1);
	}

	stack_destroy(&s);
	return data;
}
