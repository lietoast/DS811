#ifndef _SEQ_LIST_H__
#define _SEQ_LIST_H__

#ifndef DS_811_STATUS__
#define ERROR       0 // 出现错误
#define OK          1 // 运行通过
#define OVERFLOW    2 // 上溢
#define UNDERFLOW   3 // 下溢
#define NOT_PRESENT 4 // 元素不存在
#define DUPLICATE   5 // 有重复元素
typedef int status_t;
#endif

typedef int elem_t; // 表中元素的类型

struct seq_list
{
	int len;          // 表中元素个数
	int cap;          // 顺序表最大允许长度
	elem_t *elements; // 实际存储结构为顺序结构
};

typedef struct seq_list sqlist_t;

status_t seq_list_init(sqlist_t *list);
// 顺序表的查找
status_t seq_list_find(sqlist_t list, int i, elem_t *x);
// 返回顺序表的长度
int seq_list_length(sqlist_t list);
// 顺序表插入元素
status_t seq_list_insert(sqlist_t *list, int i, elem_t x);
// 顺序表扩容
static void seq_list_incr_capacity(sqlist_t *list);
// 查看顺序表是否为空
int seq_list_is_empty(sqlist_t list);
// 顺序表元素删除
status_t seq_list_delete(sqlist_t *list, int i);
// 元素表缩容
static void seq_list_decr_capacity(sqlist_t *list);
// 顺序表更新
status_t seq_list_update(sqlist_t *list, int i, elem_t x);
// 顺序表排序
void seq_list_sort(sqlist_t *list, int (*cmpelem)(const void *, const void *));
// 顺序表清除
void seq_list_clear(sqlist_t *list);
// 顺序表撤销
void seq_list_destroy(sqlist_t *list);
// 顺序表逆置
void seq_list_reverse(sqlist_t *list);

#endif
