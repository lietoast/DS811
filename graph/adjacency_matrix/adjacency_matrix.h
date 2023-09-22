#ifndef _ADJACENCY_MATRIX_H__
#define _ADJACENCY_MATRIX_H__

#include <stdbool.h>

#ifndef GRA_ELE_TYPE
#define GRA_ELE_TYPE int
#define INFINITE (1 << 31)
#endif

typedef struct mgraph
{
	GRA_ELE_TYPE **mat; // 邻接矩阵
	int vn;             // 当前顶点数
	int en;             // 边数
}MG;

/*
 * 初始化一个有vn个顶点的有向图
 * 返回值:
 * 初始化成功时, 返回存储有向图的内存空间的首地址, 失败则返回空
 **/
MG *mgraph_init(int vn);

/*
 * 释放有向图所占内存空间
 **/
void mgraph_destroy(MG *mg);

/*
 * 判断边<u,v>是否存在于有向图中
 * 返回值:
 * 若存在, 返回true, 否则返回false
 **/
bool mgraph_exist(MG *mg, int u, int v);

/*
 * 插入边<u,v>, 其权为w
 * 返回值:
 * 插入成功返回0, 如果待输入边已存在于图中, 则返回1
 * 出错返回-1
 **/
int mgraph_insert_edge(MG *mg, int u, int v, GRA_ELE_TYPE w);

/*
 * 从图中删除边<u,v>
 * 返回值:
 * 删除成功返回0, 如果待删除边不存在或发生其他错误, 返回-1
 **/
int mgraph_rm_edge(MG *mg, int u, int v);
#endif
