#include <stdio.h>
#include "arrayHeap.h"

void displayArrayHeap(ArrayHeap* pArrayHeap)
{
	if (pArrayHeap != NULL) {
		for (int i = 1; i <= pArrayHeap->currentElementCount; i++) {
			printf("[%d]: %d\n", i, pArrayHeap->pElement[i].key);
		}
	}
}

int main()
{
	int maxHeapsize = 7;
	ArrayHeap* pArrayHeap;
	HeapNode node;

	pArrayHeap = createArrayHeap(maxHeapsize);
	node.key = 20;
	insertHeapNode(pArrayHeap, node);
	node.key = 6;
	insertHeapNode(pArrayHeap, node);
	node.key = 12;
	insertHeapNode(pArrayHeap, node);
	node.key = 2;
	insertHeapNode(pArrayHeap, node);
	node.key = 4;
	insertHeapNode(pArrayHeap, node);
	displayArrayHeap(pArrayHeap);
	printf("--------\n");
	node.key = 30;
	insertHeapNode(pArrayHeap, node);
	displayArrayHeap(pArrayHeap);
	printf("--------\n");
	deleteHeapNode(pArrayHeap);
	displayArrayHeap(pArrayHeap);
	// printf("--------\n");
	// deleteArrayHeap(pArrayHeap);
	// displayArrayHeap(pArrayHeap);
}

