#include <stdlib.h>
#include <stdio.h>

#include "adjacency_list.h"

void show_lgraph(LG *lg)
{
	int i;
	enode_t *cur;

	for (i = 0; i < lg->vn; i ++)
	{
		for (cur = lg->arr[i]; cur != NULL; cur = cur->nextarc)
			printf("%d --%d--> %d\n", i, cur->w, cur->adjvex);
	}
}

int main(void)
{
	int vn, i;
	LG *lg;
	int u, v;
	GRA_ELE_TYPE w;

	printf("vn: ");
	scanf("%d", &vn);

	lg = lgraph_init(vn);
	if (!lg)
		exit(1);

	for (i = 0; i < 5; i ++)
	{
		scanf("%d %d %d", &u, &v, &w);
		lgraph_insert_edge(lg, u, v, w);
	}

	show_lgraph(lg);

	for (i = 0; i < 2; i ++)
	{
		scanf("%d %d", &u, &v);
		lgraph_rm_edge(lg, u, v);
	}

	show_lgraph(lg);

	exit(0);
}
