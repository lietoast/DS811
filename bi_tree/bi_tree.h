#ifndef _BINARY_TREE_H__
#define _BINARY_TREE_H__

#include <stdbool.h>

typedef void *elem_t;

typedef struct btnode // 二叉树结点
{
	elem_t element;
	struct bt_node *lchild;
	struct bt_node *rchild;
}btnode_t;

typedef struct binary_tree // 二叉树
{
	btnode_t *root;
}bi_tree_t;

/*
	二叉树初始化
*/
void create_bitree(bi_tree_t *tree);

/*
	新建结点
*/
btnode_t *buy_node(elem_t x, btnode_t *ln, btnode_t *rn);

/*
	获取root结点元素
*/
bool root(bi_tree_t tree, elem_t *x);

/*
	建立二叉树
*/
void make_tree(bi_tree_t *tree, elem_t x, bi_tree_t *l, bi_tree_t *r);

#endif
