#include <stdlib.h>
#include <stdio.h>

#include "bi_tree.h"

void print_elem(void *elem)
{
	char *data = elem;
	printf("%s", data);
}

int main(void)
{
	bi_tree_t a, b, x, y, z;

	create_bitree(&a);
	create_bitree(&b);
	create_bitree(&x);
	create_bitree(&y);
	create_bitree(&z);

	//     B
	//    / \
	//   D   C
	//      / \
	//     E   F
	make_tree(&y, "E", &a, &b);
	make_tree(&z, "F", &a, &b);
	make_tree(&x, "C", &y, &z);
	make_tree(&y, "D", &a, &b);
	make_tree(&z, "B", &y, &x);
	
	printf("preorder:\n");
	preorder(z, false, print_elem);

	printf("levelorder:\n");
	levelorder(z, print_elem);

	printf("new tree:\n");
	char *nodes[11] = {"B", "D", NULL, NULL, "C", "E", NULL, NULL, "F", NULL, NULL};
	pre_make_tree(&z, nodes, 11);

	levelorder(z, print_elem);
	
	clear_tree(&z);

	exit(0);
}
