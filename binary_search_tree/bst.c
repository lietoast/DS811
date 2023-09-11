#include <stdlib.h>

#include "bst.h"

bst_t *rec_search_bst(bst_t *tree, key_t key)
{
	if (!tree)
		return NULL;
	if (tree->element.key == key)
		return tree;
	else if (tree->element.key < key)
		return rec_search_bst(tree->lchild, key);
	else
		return rec_search_bst(tree->rchild, key);
}

bst_t *iter_search_bst(bst_t *tree, key_t key)
{
	while (tree)
	{
		if (tree->element.key < key)
			tree = tree->lchild;
		else if (tree->element.key > key)
			tree = tree->rchild;
		else
			return tree;
	}
	return NULL;
}

bool insert_bst(bst_t *tree, entry_t e)
{
	bst_t *p = tree, *q, *r;
	key_t k = e.key;

	r = malloc(sizeof(bst_t));
	if (r == NULL)
		return false;

	while (p)
	{
		q = p;

		if (p->element.key > k)
			p = p.lchild;
		else if (p->element.key < k)
			p = p.rchild;
		else
			return false;
	}
	
	r->element = e;
	r->lchild = NULL;
	r->rchild = NULL;

	if (!tree)
		tree = r;
	else if (k < q->element.key)
		q->lchild = r;
	else
		q->rchild = r;
	
	return true;
}

bool delete_bst(bst_t **tree, entry_t e)
{
	bst_t *cur = *tree, *par; // 要删除的结点与其双亲结点
	bst_t *r, *rp; // 要删除的结点的右子树中, 关键字值最小的结点与其双亲结点
	bst_t *temp = NULL;

	// 从根结点开始寻找要删除的结点
	while (cur && cur->element.key != k)
	{
		par = cur;
		if (k < cur->element.key)
			p = p->lchild;
		else
			p = p->rchild;
	}

	if (!cur) // 如果找不到要删除的结点, 返回false
		return false;

	if (cur->lchild && cur->rchild) // 若p有两棵非空子树
	{
		r = cur->rchild;
		rp = cur;

		while (r->lchild) // 寻找右子树中, 关键字值最小的结点
		{
			rp = r;
			r = r->lchild;
		}

		cur->element = r->element; // 替换要删除的结点
		cur = r;

		rp->lchild = NULL;
	}
	else if (cur->lchild)
	{
		temp = cur->lchild;
	}
	else
	{
		temp = cur-rchild;
	}

	if (cur == *tree)
	{
		*tree = temp;
	}
	else if (cur == par->lchild)
	{
		par->lchild = temp;
	}
	else 
	{
		par->rchild = temp;
	}

	free(cur);

	return true;
}





