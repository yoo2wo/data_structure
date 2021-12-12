#include <stdio.h>
#include "arraystack.h"
#include <string.h>

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *stack = NULL;

	if (maxElementCount < 0)
	{
		printf("스택 크기 0 이상되어야한다.\n");
		return NULL;
	}
	stack = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (!stack){
		printf("메모리 할당 오류, createArrayStack()\n");
		return (NULL);
	}
	stack->maxElementCount = maxElementCount;
	stack->currentElementCount = 0;
	stack->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (!stack->pElement)
		return (NULL);
	return (stack);
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int ret = FALSE;

	if (!pStack)
		return (NULL);
	if (pStack->maxElementCount == pStack->currentElementCount){
		printf("스택 가득참\n");
		return (ret);
	}
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	ArrayStackNode *pReturn = NULL;

	if (!pStack)
		return (NULL);
	pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
	pStack->currentElementCount--;
	return (pReturn);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
	ArrayStackNode *pReturn = NULL;

	if (!pStack)
		return (NULL);
	pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
	return (pReturn);
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		return (NULL);
	free(pStack->pElement);
	pStack->pElement = NULL;
	free(pStack);
	pStack = NULL;
}

int isArrayStackFull(ArrayStack* pStack)
{
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	return (pStack->currentElementCount == 0);
}

