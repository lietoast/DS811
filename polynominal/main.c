#include <stdlib.h>
#include <stdio.h>

#include "polynominal.h"

int main(void)
{
	polynominal_t p, q;

	polynominal_create(&p);
	polynominal_create(&q);

	polynominal_t *r = polynominal_add(&p, &q);
	polynominal_output("result", r);

	exit(0);
}
