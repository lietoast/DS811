#ifndef _LINKED_LIST_H__
#define _LINKED_LIST_H__

#include <stdlib.h>

#ifndef DS_811_STATUS__
#define ERROR       0 // 出现错误
#define OK          1 // 运行通过
#define OVERFLOW    2 // 上溢
#define UNDERFLOW   3 // 下溢
#define NOT_PRESENT 4 // 元素不存在
#define DUPLICATE   5 // 有重复元素
typedef int status_t;
#endif

// 多项式的项
typedef struct polynominal_item
{
	int coef; // 系数
	int exp;  // 指数
}pitem_t;

typedef pitem_t elem_t;

// 双向环链的结点声明
typedef struct du_linked_list_node
{
	struct du_linked_list_node *llink;
	struct du_linked_list_node *rlink;
	elem_t element;
}lklnode_t;

// 双向环链类型声明
typedef struct du_linked_list
{
	lklnode_t *first;
	lklnode_t *last;
	size_t len;
}lklist_t;

// 初始化链表
// 初始化完成后，链表内仅含一个头结点，其长度为0
// 返回值：
// 如成功，返回OK；如内存空间不足，返回ERROR
status_t list_init(lklist_t *list);

// 向链表内i位置处插入数据x
// 返回值：
// 如成功，返回OK；否则返回ERROR
status_t list_insert(lklist_t *list, size_t i, elem_t x);

// 删除链表内i位置处元素
// 返回值：
// 如成功，返回OK，越界返回ERROR
status_t list_delete(lklist_t *list, size_t i);

// 清空链表内元素
void list_clear(lklist_t *list);

// 销毁链表
void list_destroy(lklist_t *list);

// 查找链表内i位置处的元素，通过p返回
// 返回值：
// 如成功，返回OK，否则返回ERROR
status_t list_find(lklist_t *list, size_t i, elem_t *p);

// 查看链表是否为空
// 返回值：
// 为空返回1，否则返回0
int list_is_empty(lklist_t *list);

// 查看链表长度
size_t list_length(lklist_t *list);

// 更新链表内i位置处元素的值
// 返回值：
// 如成功返回OK，越界返回ERROR
status_t list_update(lklist_t *list, size_t i, elem_t x);

// 将链表内元素的值输出到标准输出上
void list_output(lklist_t *list);

// 创建新的链表结点
static status_t buy_node(lklnode_t **ptr, elem_t val);

// 销毁链表的结点
static void ret_node(lklnode_t *n);

#endif
