#include "arrayHeap.h"
#include <stdio.h>
#include <stdlib.h>

ArrayHeap *createArrayHeap(int maxElementCount)
{
	ArrayHeap *pArrayHeap;
	HeapNode *pElement;

	if (maxElementCount <= 0)
		return (NULL);
	pArrayHeap = (ArrayHeap *)malloc(sizeof(ArrayHeap));
	pElement = (HeapNode *)malloc(sizeof(HeapNode) * (maxElementCount + 1));
	if (!pElement || !pArrayHeap)
		return (NULL);
	pArrayHeap->pElement = pElement;
	pArrayHeap->maxElementCount = maxElementCount;
	pArrayHeap->currentElementCount = 0;
	for(int i = 1; i <= maxElementCount; i++){
		pArrayHeap->pElement[i].key = 0;
	}
	return (pArrayHeap);
}

void insertHeapNode(ArrayHeap *pArrayHeap, HeapNode Element)
{
	int i;
	HeapNode temp;

	if (!pArrayHeap)
		return ;
	i = ++(pArrayHeap->currentElementCount);
	if (i > pArrayHeap->maxElementCount){
		printf("배열이 가득 찼습니다.\n");
		return ;
	}
	pArrayHeap->pElement[i] = Element;
	while(1){
		if ((pArrayHeap->pElement[i].key <= pArrayHeap->pElement[i/2].key) || i <= 1)
			break;
		temp = pArrayHeap->pElement[i];
		pArrayHeap->pElement[i] = pArrayHeap->pElement[i/2];
		pArrayHeap->pElement[i/2] = temp;
		i /= 2;
	}
}

HeapNode *deleteHeapNode(ArrayHeap *pArrayHeap)//리턴값이 정확히 먼지 모르겠다.
{
	HeapNode *temp;
	HeapNode *pReturn;
	int i;
	int parent;
	int child;

	if (!pArrayHeap)
		return (NULL);
	if (pArrayHeap->currentElementCount < 1)
		return (NULL);
	pReturn = (HeapNode *)malloc(sizeof(HeapNode));
	*pReturn = pArrayHeap->pElement[1];

	i = pArrayHeap->currentElementCount--;
	temp = &(pArrayHeap->pElement[i]);

	parent = 1;
	child = 2;
	while (child <= pArrayHeap->currentElementCount) {
		if ((child < pArrayHeap->currentElementCount)
			&& (pArrayHeap->pElement[child].key < pArrayHeap->pElement[child + 1].key)){
				child++;
		}
		if (temp->key >= pArrayHeap->pElement[child].key){
			break;
		}
		pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
		parent = child;
		child *= 2;
	}
	pArrayHeap->pElement[parent] = *temp;
	return (pReturn);
}

void deleteArrayHeap(ArrayHeap *pArrayHeap)
{
	while(pArrayHeap->currentElementCount)
		deleteHeapNode(pArrayHeap);
	free(pArrayHeap);
}
