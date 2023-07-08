#ifndef _HEADER_LIST_H__
#define _HEADER_LIST_H__

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

struct single_list_node
{
    elem_t element;                 // 结点的数据域
    struct single_list_node *link;  // 结点的指针域
};

typedef struct single_list_node sgln_t;

struct header_list
{
	sgln_t *head;
	int len;
};

typedef struct header_list hdlist_t;

/*
	初始化
	构造一个仅带有表头结点的空的单链表
*/
status_t header_list_init(hdlist_t *list);

/*
	插入
	插入元素时不需要单独处理插入头结点之前的情况
*/
status_t header_list_insert(hdlist_t *list, int i, elem_t x);

#endif
