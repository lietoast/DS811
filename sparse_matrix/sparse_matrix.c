#include <stdlib.h>

#include "sparse_matrix.h"

/*
	创建运算
	创建一个m*n的空稀疏矩阵
	如果成功，返回OK，否则返回ERROR
*/
status_t create_sparse_matrix(spmat_t *mat, int m, int n)
{
	if (m < 0 || n < 0)
		return ERROR;
	
	mat->m = m;
	mat->n = n;
	mat->t = 0;
	return seq_list_init(&(mat->table));
}

/*
	清除运算
	清除稀疏矩阵
*/
void destroy_sparse_matrix(spmat_t *mat)
{
	mat->m = mat->n = mat->t = 0;
	seq_list_destroy(&(mat->table));
}

/*
	赋值运算
	设置矩阵[i,j]处的元素值为x
*/
status_t store_sparse_matrix(spmat_t *mat, int i, int j, data_t x)
{
	if (mat->m * mat->n <= 0)
		return ERROR;
	if (i < 0 || j < 0 || i >= mat->m || j >= mat->n)
		return OVERFLOW;
	
}

