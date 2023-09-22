#include <stdlib.h>
#include <stdio.h>

#include "adjacency_matrix.h"

#define VNUM 10

void show_mgraph(MG *mg);

int main(void)
{
	MG *mg;

	mg = mgraph_init(VNUM);
	if (mg == NULL)
	{
		fprintf(stderr, "Graph init failed\n");
		exit(1);
	}

	mgraph_insert_edge(mg, 1, 3, 100);
	mgraph_insert_edge(mg, 2, 9, 40);
	mgraph_insert_edge(mg, 8, 2, 50);
	mgraph_insert_edge(mg, 2, 8, 30);

	show_mgraph(mg);

	mgraph_rm_edge(mg, 2, 9);

	printf("##############################\n");

	show_mgraph(mg);
	
	exit(0);
}

void show_mgraph(MG *mg)
{
	int i, j;

	for (i = 0; i < mg->vn; i ++)
	{
		for (j = i+1; j < mg->vn; j ++)
		{
			if (mgraph_exist(mg, i, j))
				printf("%d --%d--> %d\n", i, mg->mat[i][j], j);
			if (mgraph_exist(mg, j, i))
				printf("%d --%d--> %d\n", j, mg->mat[j][i], i);
		}
	}
}
