#ifndef SPARSE_MATRIX_H__
#define SPARSE_MATRIX_H__

// 稀疏矩阵中，所有非零元素用<行号,列号,值>三元组表示
typedef struct term
{
	int row, col;
	elem_t value;
}term_t;

typedef struct sparse_matrix
{
	int m, n, t;    // m为矩阵行数，n为矩阵列数，t为非零元素个数
	term_t *table;  // 存储非零元素的三元组表
}spmat_t;

/*
	创建运算
	创建一个m*n的空稀疏矩阵
	返回值
	如果成功，返回OK，否则返回ERROR
*/
status_t create_sparse_matrix(spmat_t *mat, int m, int n);

/*
	清除运算
	清除稀疏矩阵
	返回值
	成功返回OK，否则返回ERROR
*/
status_t clear_sparse_matrix(spmat_t *mat);


/*
	赋值运算
	判断矩阵是否存在，若不存在，返回ERROR；
	否则，对i、j进行下标检查，若有越界，返回ERROR；
	否则，设置稀疏矩阵中下标为[i,j]处的元素值为x，返回OK
*/
status_t store_sparse_matrix(spmat_t *mat, int i, int j, elem_t x);

/*
	查找运算
	判断稀疏矩阵是否存在，若不存在，返回ERROR；
	否则，对i、j进行下标检查，非法返回ERROR；
	否则，将矩阵中下标为[i,j]处的元素通过x返回
*/
status_t retrieve_sparse_matrix(spmat_t *mat, int i, int j);

/*
	输出运算
*/
void output_sparse_matrix(spmat_t *mat, void (*output_elem)(elem_t));

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
status_t add_sparse_matrix(spmat_t *x, spmat_t *y, spmat_t *sum);

/*
	乘法运算
	判断两矩阵是否满足同时存在且x的列数等于y的行数，若不满足，返回ERROR；
	否则，通过product返回两矩阵的积
*/
status_t multi_sparse_matrix(spmat_t *x, spmat_t *y, spmat_t *product);

#endif
