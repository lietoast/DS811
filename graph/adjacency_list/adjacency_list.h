#ifndef _ADJACENCY_LIST_H__
#define _ADJACENCY_LIST_H__

#include "stdbool.h"

#ifndef GRA_ELE_TYPE
#define GRA_ELE_TYPE int
#define INFINITE (1 << 31)
#endif

typedef struct edge_node // 邻接表所维护的单链表中, 每一个结点代表图中一条边
{
	int adjvex;                // adjvex临接自LG.arr[i]
	GRA_ELE_TYPE w;            // 边的权
	struct edge_node *nextarc; // 另一个始点为LG.arr[i]的边
}enode_t;

typedef struct lgraph
{
	int vn;        // 当前顶点数
	int en;        // 当前边数
	enode_t **arr; // 指针数组
}LG;

/*
 * 初始化一个有vn个顶点的有向图
 * 返回值:
 * 初始化成功时, 返回存储有向图的内存空间的首地址, 失败则返回空
 **/
LG *lgraph_init(int vn);

/*
 * 释放有向图占用的内存空间
 **/
void lgraph_destroy(LG *lg);

/*
 * 判断边<u,v>是否存在于有向图中
 * 返回值:
 * 若存在, 返回true, 否则返回false
 **/
bool lgraph_exist(LG *lg, int u, int v);

/*
 * 插入边<u,v>, 其权为w
 * 返回值:
 * 插入成功返回0, 如果待输入边已存在于图中, 则返回1
 * 出错返回-1
 **/
int lgraph_insert_edge(LG *lg, int u, int v, GRA_ELE_TYPE w);

/*
 * 从图中删除边<u,v>
 * 返回值:
 * 删除成功返回0, 如果待删除边不存在或发生其他错误, 返回-1
 **/
int lgraph_rm_edge(LG *lg, int u, int v);

#endif
