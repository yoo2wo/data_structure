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
	// int maxHeapsize = 7;
	// ArrayHeap* pArrayHeap;
	// HeapNode node;

	// pArrayHeap = createArrayHeap(maxHeapsize);
	// pArrayHeap->pElement[1].key = 20;
	// pArrayHeap->pElement[2].key = 6;
	// pArrayHeap->pElement[3].key = 12;
	// pArrayHeap->pElement[4].key = 2;
	// pArrayHeap->pElement[5].key = 4;
	// displayArrayHeap(pArrayHeap);

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
}

