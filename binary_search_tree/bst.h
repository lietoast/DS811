#ifndef _BST_H__
#define _BST_H__

#include <stdbool.h>

typedef long key_t;

// 动态集元素类型
typedef struct entry
{
	key_t key;  // 二叉搜索树的关键字值
	void *data; // 二叉搜索树中保存的数据
}entry_t;

// 二叉搜索树
typedef struct bst
{
	entry_t element;
	struct bst *lchild, rchild;
}bst_t;

// 二叉搜索树的递归搜索
bst_t *rec_search_bst(bst_t *tree, key_t key);

// 二叉搜索树的迭代搜索
bst_t *iter_search_bst(bst_t *tree, key_t key);

// 插入操作, 将结点e插入到二叉搜索树中
// 成功返回true, 否则返回false
bool insert_bst(bst_t *tree, entry_t e);


#endif
