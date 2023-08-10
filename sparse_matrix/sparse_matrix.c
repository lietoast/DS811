#include <stdlib.h>

#include "sparse_matrix.h"

#define MATRIX_SIZE 100

/*
	创建运算
	创建一个m*n的空稀疏矩阵
	返回值
	如果成功，返回OK，否则返回ERROR
*/
status_t create_sparse_matrix(spmat_t *mat, int m, int n)
{
	mat->table = malloc(MATRIX_SIZE * sizeof(term_t));
	if (mat->table == NULL)
		return ERROR;
	mat->m = m;
	mat->n = n;
	mat->t = 0;
	return OK;
}

/*
	清除运算
	清除稀疏矩阵
	返回值
	成功返回OK，否则返回ERROR
*/
status_t destroy_sparse_matrix(spmat_t *mat)
{
	if (mat->table == NULL)
		return ERROR;
	
	free(mat->table);
	mat->table = NULL;
	mat->t = 0;

	return OK;
}

static int termcmp(term_t x, term_t y)
{
	if (x.row < y.row)
		return -1;
	return x.col - y.col;
}

static int search(spmat_t *mat, int i, int j)
{
	int low = 0, high = mat->t + 1;
	int mid = low + ((high - low)>>1);
	
	term_t tmp;
	tmp.row = i;
	tmp.col = j;

	while (low < high)
	{
		int flag = termcmp(mat->table[mid], tmp);
		if (!flag)
			return mid;

		if (flag < 0)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
		mid = low + ((high - low)>>1);
	}

	return -1;
}

/*
	赋值运算
	判断矩阵是否存在，若不存在，返回ERROR；
	否则，对i、j进行下标检查，若有越界，返回ERROR；
	否则，设置稀疏矩阵中下标为[i,j]处的元素值为x，返回OK
*/
status_t store_sparse_matrix(spmat_t *mat, int i, int j, elem_t x)
{
	if (mat->table==NULL||i<0||j<0||i>=mat->m||j>=mat->n)
		return ERROR;
	
	int index = search(mat, i, j);
	if (index >= 0)
	{
		mat->table[index] = x;
		return OK;
	}

	if (mat->t >= MATRIX_SIZE)
		return ERROR;

	term_t t;
	t.row = i;
	t.col = j;
	t.value = x;

	for (index = 0; index < mat->t; index ++)
		if (termcmp(mat->table[index], t) > 0) // 懒得再写二分法了(;_;)
			break;
	
	for (i = mat->t; i > index; i --)
		mat->table[i] = mat->table[i - 1];

	mat->table[index] = t;
	mat->t ++;

	return OK;
}

/*
	查找运算
	判断稀疏矩阵是否存在，若不存在，返回ERROR；
	否则，对i、j进行下标检查，非法返回ERROR；
	否则，将矩阵中下标为[i,j]处的元素通过x返回
*/
status_t retrieve_sparse_matrix(spmat_t *mat, int i, int j, elem_t *x)
{
	if (mat->table==NULL||i<0||j<0||i>=mat->m||j>=mat->n)
		return ERROR;
	
	int index = search(mat, i, j);
	if (index < 0)
		return ERROR;

	*x = mat->table[index].value;
	return OK;
}

/*
	输出运算
*/
void output_sparse_matrix(spmat_t *mat, void (*output_elem)(elem_t))
{
	printf("[\n");

	int i, j;
	for (i = 0; i < mat->m; i ++)
	{
		printf("[")
		for (j = 0; j < mat->n; j ++)
		{
			if (search(mat, i, j) < 0)
			{
				printf("0.00, ");
			}
			else
			{
				output_elem(mat->table[search(mat, i, j)].value);
				printf(", ")
			}
		}
		printf("\b]\n");
	}

	printf("]\n");
}

/*
	转置运算
	判断稀疏矩阵mat是否存在，若不存在，返回ERROR；
	否则，通过t返回mat的转置矩阵
*/
status_t transpose_sparse_matrix(spmat_t *mat, spmat_t *t);

/*
	加法运算
	判断两矩阵是否满足同时存在且形状一样，若不满足，返回ERROR；
	否则，通过sum返回两矩阵的和
*/
status_t add_sparse_matrix(spmat_t *x, spmat_t *y, spmat_t *sum)
{
	
}

/*
	乘法运算
	判断两矩阵是否满足同时存在且x的列数等于y的行数，若不满足，返回ERROR；
	否则，通过product返回两矩阵的积
*/
status_t multi_sparse_matrix(spmat_t *x, spmat_t *y, spmat_t *product);


