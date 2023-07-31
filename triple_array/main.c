#include <stdlib.h>
#include <stdio.h>

#include "triarr.h"

void print_elem(elem_t elem);

int main(void)
{
	triarr_t A, B;
	create_array(&A, 2, 2, 2);
	create_array(&B, 2, 2, 2);

	int i, j, k;
	for (i = 0; i < A.m1; i ++)
		for (j = 0; j < A.m2; j ++)
			for (k = 0; k < A.m3; k ++)
			{
				store_array_item(&A, i, j, k, 5);
				store_array_item(&B, i, j, k, 10);
			}

	output_array(A, print_elem);
	output_array(B, print_elem);

	copy_array(&A, &B);

	output_array(A, print_elem);
	output_array(B, print_elem);

	exit(0);
}

void print_elem(elem_t elem)
{
	printf("%d", elem);
}
