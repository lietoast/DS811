#include "hash_table.h"

#define NEVER_USED -99

// 初始化散列表
void create_hash_table(HT *tb, int size)
{
	int i;

	if (size <= 0)
		return;

	tb->cap = size;
	tb->num = 0;
	tb->empty = malloc(size * sizeof(bool));
	if (!tb->empty)
	{
		tb->cap = 0;
		return;
	}
	tb->elements = malloc(size * sizeof(int));
	if (!tb->elements)
	{
		tb->cap = 0;
		free(tb->empty);
		tb->empty = NULL;
		return;
	}

	for (i = 0; i < size; i ++)
	{
		ht->empty[i] = true;
		ht->elemtns[i] = NEVER_USED;
	}
}

// 释放散列表所占的存储空间
void destroy_hash_table(HT *tb)
{
	free(tb->empty);
	free(tb->elements);
	
	tb->cap = 0;
	tb->num = 0;
	tb->empty = NULL;
	tb->elements = NULL;
}

// 清空散列表
void clear_hash_table(HT *tb)
{
	int i;

	if (ht_empty(tb))
		return;
	tb->num = 0;

	for (i = 0; i < tb->cap; i ++)
	{
		tb->empty[i] = true;
		tb->elements[i] = NEVER_USED;
	}
}

// 判断散列表是否为空, 为空则返回true, 否则返回false
bool ht_empty(HT *tb)
{
	return tb->num <= 0;
}

// 判断散列表是否已满, 若已满返回true, 否则返回false
bool ht_full(HT *tb)
{
	return tb->num >= tb->cap;
}

// 基于去余数法的散列函数
int hash(int key, int mod)
{
	return key % mod; 
}

// 在散列表中查找关键字值为key的元素
// 若存在, 返回该元素的位置
// 否则, 返回-1
int search_hash_table(HT *tb, int key)
{
	int anchor, pos;

	anchor = pos = hash(key, tb->cap); // 计算基地址

	do {
		if (tb->empty[pos])
			return -1;
		else if (tb->element[pos] == key)
			return pos;
		pos = (pos+1)%tb->cap;
	} while (pos != anchor);

	return -1;
}

// 在散列表中插入关键字值为key的元素
int insert_hash_table(HT *tb, int key)
{
	int anchor, i;

	if (ht_full(tb))
		return -1;
	if ((anchor = search_hash_table(tb, key)) >= 0)
		return anchor;
	
	anchor = i = hash(key, tb->cap);
	
	do {
		if (tb->elements[i] == NEVER_USED)
		{
			tb->elements[i] = key;
			ht->empty[i] = false;
			ht->num ++;
			return i;
		}
	} while (i != anchor);

	return -1;
}

// 从散列表中删除关键字值为key的元素
int delete_hash_table(HT *tb, int key)
{
	int pos, r;

	if (ht_empty(tb))
		return NEVER_USED;

	pos = search_hash_table(tb, key);
	if (pos < 0)
		return NEVER_USED;
	else
	{
		r = tb->elements[pos];
		tb->elements[pos] = NEVER_USED;
		ht->num ++;
		return r;
	}
}


