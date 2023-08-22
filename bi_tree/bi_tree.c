#include <stdlib.h>
#include <stdio.h>

#include "bi_tree.h"

/*
   二叉树初始化
 */
void create_bitree(bi_tree_t *tree)
{
	tree->root = NULL;
}

/*
   新建结点
 */
btnode_t *buy_node(elem_t x, btnode_t *ln, btnode_t *rn)
{
	btnode_t *n = malloc(sizeof(btnode_t));

	n->element = x;
	n->lchild = ln;
	n->rchild = rn;

	return n;
}

/*
   获取root结点元素
 */
bool root(bi_tree_t tree, elem_t *x)
{
	if (!tree.root)
		return false;

	x = &(tree.root->element);
	return true;
}

/*
   建立二叉树
 */
void make_tree(bi_tree_t *tree, elem_t x, bi_tree_t *l, bi_tree_t *r)
{
	if (tree->root || l == r)
		return;

	tree->root = buy_node(x, l->root, r->root);
	l->root = r->root = NULL;
}

void preorder_rec(btnode_t *root, void (*print_elem)(void *))
{
	if (!root)
		return;

	print_elem(root->element);
	printf("\n");

	preorder_rec(root->lchild, print_elem);
	preorder_rec(root->rchild, print_elem);
}

/*
   先序遍历, traverse为真时采用遍历策略, 否则采取递归
 */
void preorder(bi_tree_t tree, bool traverse, void (*print_elem)(void *))
{
	if (traverse)
	{
		// 未完成
	}
	else
	{
		preorder_rec(tree.root, print_elem);
	}
}

/*
   层次遍历
 */
void levelorder(bi_tree_t tree, void (*print_elem)(void *))
{
	if (tree.root == NULL)
		return;

	btnode_t *q[MAX_QS_SIZE];
	q[0] = tree.root;
	int l = 0, r = 1; // 上一层, 下一层末尾位置

	for (; l < r; l ++)
	{
		if (q[l]->lchild != NULL)
			q[r ++] = q[l]->lchild;
		if (r >= MAX_QS_SIZE)
			break;
		if (q[l]->rchild != NULL)
			q[r ++] = q[l]->rchild;
		if (r >= MAX_QS_SIZE)
			break;
	}

	for (l = 0; l < r; l ++)
	{
		print_elem(q[l]->element);
		printf("\n");
	}
}

void clear(btnode_t *root)
{
	if (!root)
		return;
	
	clear(root->lchild);
	clear(root->rchild);

	free(root);
}

/*
	清空二叉树
*/
void clear_tree(bi_tree_t *tree)
{
	clear(tree->root);
	tree->root = NULL;
}

/*
	递归先序遍历构建二叉树
*/
btnode_t *pre_create_bt(elem_t *elements, int nele, int *i)
{
	if (*i >= nele || elements[*i] == NULL)
	{
		*i += 1;
		return NULL;
	}

	btnode_t *n = malloc(sizeof(btnode_t));
	n->element = elements[*i];
	*i += 1;
	n->lchild = pre_create_bt(elements, nele, i);
	n->rchild = pre_create_bt(elements, nele, i);
	return n;
}

/*
	先序构建二叉树
*/
void pre_make_tree(bi_tree_t *tree, elem_t *elements, int n)
{
	int i = 0;
	tree->root = pre_create_bt(elements, n, &i);
}












