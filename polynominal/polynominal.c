#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"
#include "polynominal.h"

// 创建多项式
void polynominal_create(polynominal_t *p)
{
	list_init(p);
	printf("Please input <coef,exp>(s) (end with <n,-n>, n>0):\n");
	for (;;)
	{
		pitem_t item;
		scanf("%d,%d", &item.coef, &item.exp);
		if (item.exp < 0)
			break;

		list_insert(p, list_length(p), item);
	}
}

// 多项式相加
polynominal_t *polynominal_add(polynominal_t *f, polynominal_t *g)
{
	lklnode_t *fp = f->first->rlink, *gp = g->first->rlink;

	lklist_t *res = malloc(sizeof(lklist_t));
	list_init(res);

	while (fp != f->first && gp != g->first)
	{
		pitem_t item;
		if (gp == g->first || (fp->element).exp > (gp->element).exp)
		{
			item = fp->element;
			list_insert(res, list_length(res), item);
			fp = fp->rlink;
		}
		else if (fp == f->first || (fp->element).exp < (gp->element).exp)
		{
			item = gp->element;
			list_insert(res, list_length(res), item);
			gp = gp->rlink;
		}
		else
		{
			int coef = (fp->element).coef + (gp->element).coef;
			if (coef)
			{
				item.coef = coef;
				item.exp = (fp->element).exp;
				list_insert(res, list_length(res), item);
			}

			fp = fp->rlink;
			gp = gp->rlink;
		}
	}

	return res;
}

// 输出多项式
void polynominal_output(char *pname, polynominal_t *p)
{
	if (list_is_empty(p))
	{
		printf("%s: 0\n", pname);
		return;
	}

	printf("%s: ", pname);

	lklnode_t *n = p->first->rlink;
	for (; n != p->first; n = n->rlink)
	{
		pitem_t item = n->element;
		if (item.coef > 0 && n != p->first->rlink)
			printf("+");
		printf("%dx^%d", item.coef, item.exp);
	}

	printf("\n");
}
