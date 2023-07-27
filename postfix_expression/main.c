#include <stdlib.h>
#include <stdio.h>

#include "postfix_expr.h"
#include "../tools/iopp.h"

#define POSTFIX_EXPR_SIZE 100

int main(void)
{
	char postfix[POSTFIX_EXPR_SIZE]; // 存储表达式
	
	printf("Please input postfix expression: ");
	get_stdin_line(postfix, POSTFIX_EXPR_SIZE);

	if (!is_legal(postfix))
	{
		fprintf(stderr, "illegal postfix expression: %s\n", postfix);
		exit(-1);
	}

	printf("%s = %.2f\n", postfix, cal_postfix_expr(postfix));

	exit(0);
}
