#ifndef _BINARY_TREE_H__
#define _BINARY_TREE_H__

#include <stdbool.h>

// 遍历时使用的栈/队列的最大容量
#define MAX_QS_SIZE 1000

#define elem_t void *

typedef struct btnode // 二叉树结点
{
	elem_t element;
	struct btnode *lchild;
	struct btnode *rchild;
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

/*
	先序遍历, traverse为真时采用遍历策略, 否则采取递归
*/
void preorder(bi_tree_t tree, bool traverse, void (*print_elem)(void *));

/*
	层次遍历
*/
void levelorder(bi_tree_t tree, void (*print_elem)(void *));

/*
	清空二叉树
*/
void clear_tree(bi_tree_t *tree);

/*
	先序构建二叉树
*/
void pre_make_tree(bi_tree_t *tree, elem_t *elements, int n);

#endif
