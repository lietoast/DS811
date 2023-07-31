#include <stdlib.h>
#include <stdio.h>

#include "triarr.h"

/*
	创建运算:
	申请3维数组arr所需空间(m1*m2*m3大小)并分配给数组A
	返回值:
	成功分配则函数返回OK, 否则返回ERROR
*/
status_t create_array(triarr_t *arr, int m1, int m2, int m3)
{
	arr->m1 = m1;
	arr->m2 = m2;
	arr->m3 = m3;
	arr->array = malloc(m1 * m2 * m3 * sizeof(elem_t));
	if (arr->array == NULL)
		return ERROR;
	return OK;
}

/*
	清除运算:
	判断数组arr是否存在, 若存在, 则撤销数组, 函数返回OK, 否则返回ERROR
*/
status_t destroy_array(triarr_t *arr)
{
	if (arr->array == NULL)
		return ERROR;
	free(arr->array);
	arr->m1 = arr->m2 = arr->m3 = 0;
	return OK;
}

/*
	数组元素查询运算:
	判断数组arr是否存在, 若不存在, 则函数返回ERROR;
	否则, 对i1, i2, i3进行边界检查, 若下标非法, 则返回ERROR;
	否则通过x返回下标为i1, i2, i3的元素
*/
status_t retrieve_array(triarr_t arr, int i1, int i2, int i3, elem_t *x)
{
	if (!arr.array)
		return NOT_PRESENT;
	if (i1*i2*i3<0||i1 >= arr.m1||i2 >= arr.m2||i3 >= arr.m3)
		return ILLEGAL_INDEX;
	*x = *(arr.array + i1*arr.m2*arr.m3 + i2*arr.m3 + i3);
	return OK;
}

/*
	数组元素赋值运算:
	判断数组arr是否存在, 若不存在, 返回ERROR;
	否则对i1, i2, i3进行边界检查, 若下标非法, 返回ERROR;
	否则将数组下标为i1, i2, i3处赋值为x
*/
status_t store_array_item(triarr_t *arr, int i1, int i2, int i3, elem_t x)
{
	if (!arr->array)
		return NOT_PRESENT;
	if (i1*i2*i3<0||i1 >= arr->m1||i2 >= arr->m2||i3 >= arr->m3)
		return ILLEGAL_INDEX;
	*(arr->array + i1*arr->m2*arr->m3 + i2*arr->m3 + i3) = x;
	return OK;
}

/*
	数组输出:
	判断数组arr是否存在, 若不存在, 则函数返回;
	否则, 将函数中所有元素依次输出
*/
void output_array(triarr_t arr, void (*print_elem)(elem_t))
{
	if (!arr.array)
		return;
	
	printf("[\n");
	int i, j, k;
	for (i = 0; i < arr.m1; i ++)
	{
		printf("\t[\n");
		for (j = 0; j < arr.m2; j ++)
		{
			printf("\t\t[");
				for (k = 0; k < arr.m3; k ++)
				{
					if (k < arr.m3-1)
					{
						print_elem(arr.array[k]);
						printf(", ");
					}
					else
					{
						print_elem(arr.array[k]);
					}
				}
			printf("]\n");
		}
		printf("\t]\n");
	}
	printf("]\n");
}

/*
	数组拷贝:
	判断数组src和dest是否存在, 若其中一个不存在, 返回ERROR;
	否则, 判断src和dest维度是否相同, 若不同, 函数返回ERROR;
	否则, 将src中的所有元素拷贝到dest中
*/
status_t copy_array(triarr_t *src, triarr_t *dest)
{
	if (!src->array || !dest->array)
		return NOT_PRESENT;
	if (src->array == dest->array)
		return DUPLICATE;
	if (src->m1 != dest->m1 || src->m2 != dest->m2 || src->m3 != dest->m3)
		return ERROR;
	int i, j, k;
	for (i = 0; i < src->m1; i ++)
		for (j = 0; j < src->m2; j ++)
			for (k = 0; k < src->m3; k ++)
			{
				int value;
				retrieve_array(*src, i, j, k, &value);
				store_array_item(dest, i, j, k, value);
			}
	return OK;
}


