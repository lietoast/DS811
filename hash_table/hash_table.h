#ifndef _HASH_TABLE_H__
#define _HASH_TABLE_H__

#include <stdbool.h>

typedef struct hash_table
{
	int cap;       // 散列表的长度
	int num;       // 散列表中存储的元素数量
	bool *empty;   // 标记数组
	int *elements; // 元素数组, 为了简化程序, 假设每一个元素只存储关键字
}HT;

// 初始化散列表
void create_hash_table(HT *tb, int size);
// 释放散列表所占的存储空间
void destroy_hash_table(HT *tb);
// 清空散列表
void clear_hash_table(HT *tb);
// 判断散列表是否为空, 为空则返回true, 否则返回false
bool ht_empty(HT *tb);
// 判断散列表是否已满, 若已满返回true, 否则返回false
bool ht_full(HT *tb);
// 基于去余数法的散列函数
int hash(int key, int mod);
// 在散列表中查找关键字值为key的元素
// 若存在, 返回该元素的位置
// 否则, 返回-1
int search_hash_table(HT *tb, int key);
// 在散列表中插入关键字值为key的元素
int insert_hash_table(HT *tb, int key);
// 从散列表中删除关键字值为key的元素
int delete_hash_table(HT *tb, int key);

#endif
