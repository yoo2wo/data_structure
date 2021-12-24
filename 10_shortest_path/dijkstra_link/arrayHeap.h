#ifndef ARRAYHEAP_H
#define ARRAYHEAP_H

typedef struct HeapElementType
{
	int key;
	int to;
}	HeapNode;

typedef struct ArraryHeapType
{
	int maxElementCount;
	int currentElementCount;
	HeapNode* pElement;
}	ArrayHeap;

ArrayHeap *createArrayHeap(int maxElementCount);
void deleteArrayHeap(ArrayHeap *pArrayHeap);
void insertHeapNode(ArrayHeap *pArrayHeap, HeapNode Element);
HeapNode *deleteHeapNode(ArrayHeap *pArrayHeap);

#endif
