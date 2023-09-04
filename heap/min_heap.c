#include <stdlib.h>

#include "min_heap.h"

static void adjust_down(hpnode_t heap[], int current, int border)
{
	int p = current; // 待调整的结点位置
	int min_child; // p结点的较小子结点
	hpnode_t temp;

	while ((p<<1)+1 < border) // p 不是叶子结点
	{
		if ((p<<1)+2 < border && heap[(p<<1)+2].priority <= heap[(p<<1)+1].priority)
			min_child = (p<<1) + 2; // 较小子结点为右子结点
		else 
			min_child = (p<<1) + 1; // 较小子结点为左子结点

		 // 如果当前结点的优先级不大于
		 // 较小子结点的优先级
		 // 则停止调整
		if (heap[p].priority <= heap[min_child].priority)			
			break;
		else // 否则, 调整结点位置
		{
			temp = heap[p];
			heap[p] = heap[min_child];
			heap[min_child] = temp;

			p = min_child; // 移动p以使其始终指向待调整的结点的位置
		}
	}
}

void create_heap(hpnode_t heap[], int n)
{
	int i;
	for (i = (n-2)>>1; i > -1; i --) // (n-2)/2 位置之后的结点为叶子结点
	{
		adjust_down(heap, i, n);
	}
}
