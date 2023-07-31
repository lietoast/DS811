#ifndef _TRI_ARR_H__
#define _TRI_ARR_H__

#ifndef DS_811_STATUS__
#define ERROR       0 // 出现错误
#define OK          1 // 运行通过
#define NOT_PRESENT 4 // 不存在
#define DUPLICATE   5 // 有重复元素
typedef int status_t;
#endif

#ifndef CHAP_4_STATUS__
#define ILLEGAL_STATUS 11 // 非法
#define ILLEGAL_INDEX  12 // 访问非法下标 
#endif

typedef int elem_t;

typedef struct triple_array
{
	int m1;
	int m2;
	int m3;
	elem_t *array;
}triarr_t;

/*
	创建运算:
	申请3维数组arr所需空间(m1*m2*m3大小)并分配给数组A
	返回值:
	成功分配则函数返回OK, 否则返回ERROR
*/
status_t create_array(triarr_t *arr, int m1, int m2, int m3);

/*
	清除运算:
	判断数组arr是否存在, 若存在, 则撤销数组, 函数返回OK, 否则返回ERROR
*/
status_t destroy_array(triarr_t *arr);

/*
	数组元素查询运算:
	判断数组arr是否存在, 若不存在, 则函数返回ERROR;
	否则, 对i1, i2, i3进行边界检查, 若下标非法, 则返回ERROR;
	否则通过x返回下标为i1, i2, i3的元素
*/
status_t retrieve_array(triarr_t arr, int i1, int i2, int i3, elem_t *x);

/*
	数组元素赋值运算:
	判断数组arr是否存在, 若不存在, 返回ERROR;
	否则对i1, i2, i3进行边界检查, 若下标非法, 返回ERROR;
	否则将数组下标为i1, i2, i3处赋值为x
*/
status_t store_array_item(triarr_t *arr, int i1, int i2, int i3, elem_t x);

/*
	数组输出:
	判断数组arr是否存在, 若不存在, 则函数返回;
	否则, 将函数中所有元素依次输出
*/
void output_array(triarr_t arr, void (*print_elem)(elem_t));

/*
	数组拷贝:
	判断数组src和dest是否存在, 若其中一个不存在, 返回ERROR;
	否则, 判断src和dest维度是否相同, 若不同, 函数返回ERROR;
	否则, 将src中的所有元素拷贝到dest中
*/
status_t copy_array(triarr_t *src, triarr_t *dest);

#endif
