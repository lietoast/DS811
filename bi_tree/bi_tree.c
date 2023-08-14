#include <stdlib.h>

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
}

/*
	获取root结点元素
*/
bool root(bi_tree_t tree, elem_t *x)
{
	if (!tree->root)
		return false;
	
	x = &(tree->root->element);
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


