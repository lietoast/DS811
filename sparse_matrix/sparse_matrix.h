#ifndef SPARSE_MATRIX_H__
#define SPARSE_MATRIX_H__

#include "seq_list.h"

typedef struct sparse_matrix
{
	int m, n, t;    // m为矩阵行数，n为矩阵列数，t为非零元素个数
	sqlist_t table; // 存储非零元素的三元组表
}spmat_t;

/*
	创建运算
	创建一个m*n的空稀疏矩阵
	如果成功，返回OK，否则返回ERROR
*/
status_t create_sparse_matrix(spmat_t *mat, int m, int n);

#endif
