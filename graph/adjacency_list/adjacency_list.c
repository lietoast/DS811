#include <stdlib.h>

#include "adjacency_list.h"

/*
 * 初始化一个有vn个顶点的有向图
 * 返回值:
 * 初始化成功时, 返回存储有向图的内存空间的首地址, 失败则返回空
 **/
LG *lgraph_init(int vn)
{
	LG *lg;
	int i;

	if (vn <= 0)
		return NULL;

	lg = malloc(sizeof(LG));
	if (lg == NULL)
		return NULL;
	
	lg->vn = vn;
	lg->en = 0;
	lg->arr = malloc(vn * sizeof(enode_t*));
	if (lg->arr == NULL)
	{
		free(lg);
		return NULL;
	}

	for (i = 0; i < vn; i ++)
		lg->arr[i] = NULL;
	
	return lg;
}

/*
 * 释放有向图占用的内存空间
 **/
void lgraph_destroy(LG *lg)
{
	int i;
	enode_t *temp;

	for (i = 0; i < lg->vn; i ++)
	{
		while (lg->arr[i] != NULL)
		{
			temp = lg->arr[i];
			lg->arr[i] = temp->nextarc;
			free(temp);
		}
	}

	free(lg->arr);

	free(lg);
}

/*
 * 判断边<u,v>是否存在于有向图中
 * 返回值:
 * 若存在, 返回true, 否则返回false
 **/
bool lgraph_exist(LG *lg, int u, int v)
{
	enode_t *p;

	if (u<0||v<0||u>=lg->vn||v>=lg->vn||u==v)
		return false;
	
	p = lg->arr[u];
	while (p != NULL && p->adjvex != v)
		p = p->nextarc;
	
	return p != NULL;
}

/*
 * 插入边<u,v>, 其权为w
 * 返回值:
 * 插入成功返回0, 如果待输入边已存在于图中, 则返回1
 * 出错返回-1
 **/
int lgraph_insert_edge(LG *lg, int u, int v, GRA_ELE_TYPE w)
{
	enode_t *n;

	if (u<0||v<0||u>=lg->vn||v>=lg->vn||u==v)
		return -1;
	if (lgraph_exist(lg, u, v))
		return 1;
	
	n = malloc(sizeof(enode_t));
	if (n == NULL)
		return -1;
	
	n->adjvex = v;
	n->w = w;
	n->nextarc = lg->arr[u];

	lg->arr[u] = n; // 头插

	lg->en ++;

	return 0;
}

/*
 * 从图中删除边<u,v>
 * 返回值:
 * 删除成功返回0, 如果待删除边不存在或发生其他错误, 返回-1
 **/
int lgraph_rm_edge(LG *lg, int u, int v)
{
	enode_t *p, *q;

	if (u<0||v<0||u>=lg->vn||v>=lg->vn||u==v||!lgraph_exist(lg, u, v))
		return -1;
	
	p = lg->arr[u]; q = NULL;
	while (p->adjvex != v)
	{
		q = p;
		p = p->nextarc;
	}

	if (q == NULL)
		lg->arr[u] = p->nextarc;
	else
		q->nextarc = p->nextarc;
	
	free(p);
	lg->en --;

	return 0;
}















