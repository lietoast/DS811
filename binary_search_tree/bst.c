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


