#ifndef _POLYNOMINAL_H__
#define _POLYNOMINAL_H__

#include "linked_list.h"

typedef lklist_t polynominal_t;

// 创建多项式
void polynominal_create(polynominal_t *p);

// 多项式相加
polynominal_t *polynominal_add(polynominal_t *f, polynominal_t *g);

// 输出多项式
void polynominal_output(char *pname, polynominal_t *p);

#endif
