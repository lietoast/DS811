#ifndef _SINGLE_LIST_H__
#define _SINGLE_LIST_H__

#ifndef DS_811_STATUS__
#define ERROR       0 // 出现错误
#define OK          1 // 运行通过
#define OVERFLOW    2 // 上溢
#define UNDERFLOW   3 // 下溢
#define NOT_PRESENT 4 // 元素不存在
#define DUPLICATE   5 // 有重复元素
#endif

typedef int status_t;

typedef int elem_t;

// 单链表的类型定义
struct single_list_node
{
	elem_t element;					// 结点的数据域
	struct single_list_node *link;  // 结点的指针域
};

typedef struct single_list_node sgln_t;

struct single_list
{
	sgln_t *first; // 链表的首个结点
	int len;	  // 链表中元素的个数
};

typedef struct single_list sgl_t;

/*
	初始化
	构造一个空的单链表
*/
status_t single_list_init(sgl_t *list);

/*
	单链表查找操作
	找到链表内i处的元素，并通过指针x返回
	返回值：
	如果查找成功，返回OK，如越界，返回ERROR
*/
status_t single_list_find(sgl_t *list, int i, elem_t *x);

/*
	单链表插入
	在链表的i位置处插入元素x
	返回值：
	成功返回OK，否则返回ERROR	
*/
status_t single_list_insert(sgl_t *list, int i, elem_t x);

/*
	单链表删除
	删除链表中i位置处的元素
	返回值：成功返回OK，否则返回ERROR
*/
status_t single_list_delete(sgl_t *list, int i);

/*
	单链表的输出
*/
void single_list_output(sgl_t *list);

/*
	单链表的撤销
	释放单链表所用的动态分配的内存空间，以防止内存泄漏
*/
void single_list_destroy(sgl_t *list);

/*
	单链表长度
	返回单链表长度
*/
int single_list_length(sgl_t list);

/*
	判断单链表是否为空
*/
int single_list_is_empty(sgl_t list);

/*
	单链表跟新
	更新链表内i位置处的元素值，如成功，返回OK，越界返回ERROR
*/
status_t single_list_update(sgl_t *list, int i, elem_t x);

/*
	创建结点
	在堆上开辟一块结点空间，并通过ptr返回其地址
	返回值：
	成功返回OK，否则返回ERROR
*/
static status_t buy_node(sgln_t **ptr, elem_t val);

/*
	归还结点
	释放结点所占的内存空间，并将ptr的值置为NULL
*/
static void ret_node(sgln_t *ptr);

#endif
