#include <stdlib.h>

#include "adjacency_matrix.h"

/*
 * 初始化一个有vn个顶点的有向图
 * 返回值:
 * 初始化成功时, 返回存储有向图的内存空间的首地址, 失败则返回空
 **/
MG *mgraph_init(int vn)
{
	MG *mg;
	int i, j;

	if (vn <= 0)
		return NULL;

	mg = malloc(sizeof(MG));
	if (mg == NULL)
		return NULL;
	
	mg->vn = vn;
	mg->en = 0;

	mg->mat = malloc(vn * sizeof(GRA_ELE_TYPE*));
	if (mg->mat == NULL)
	{
		free(mg);
		return NULL;
	}

	for (i = 0; i < vn; i ++)
	{
		mg->mat[i] = malloc(vn * sizeof(GRA_ELE_TYPE));
		if (mg->mat[i] == NULL)
			break;
		
		for (j = 0; j < vn; j ++)
			mg->mat[i][j] = INFINITE;
		mg->mat[i][i] = 0;
	}
	if (i < vn)
	{
		for (j = 0; j < i; j ++)
			free(mg->mat[j]);
		free(mg->mat);
		free(mg);
		return NULL;
	}

	return mg;
}

/*
 * 释放有向图所占内存空间
 **/
void mgraph_destroy(MG *mg)
{
	int i;

	for (i = 0; i < mg->vn; i ++)
		free(mg->mat[i]);
	free(mg->mat);
	free(mg);
}

/*
 * 判断边<u,v>是否存在于有向图中
 * 返回值:
 * 若存在, 返回true, 否则返回false
 **/
bool mgraph_exist(MG *mg, int u, int v)
{
	if (u<0||v<0||u>=mg->vn||v>=mg->vn||u==v||mg->mat[u][v]==INFINITE)
		return false;
	return true;
}

/*
 * 插入边<u,v>, 其权为w
 * 返回值:
 * 插入成功返回0, 如果待输入边已存在于图中, 则返回1
 * 出错返回-1
 **/
int mgraph_insert_edge(MG *mg, int u, int v, GRA_ELE_TYPE w)
{
	if (u<0||v<0||u>=mg->vn||v>=mg->vn||u==v)
		return -1;
	if (mg->mat[u][v] != INFINITE)
		return 1;
	mg->mat[u][v] = w;
	mg->en ++;
	return 0;
}

/*
 * 从图中删除边<u,v>
 * 返回值:
 * 删除成功返回0, 如果待删除边不存在或发生其他错误, 返回-1
 **/
int mgraph_rm_edge(MG *mg, int u, int v)
{
	if (u<0||v<0||u>=mg->vn||v>=mg->vn||u==v||mg->mat[u][v]==INFINITE)
		return -1;
	mg->mat[u][v] = INFINITE;
	mg->en --;
	return 0;
}








