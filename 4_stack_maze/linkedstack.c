#include "linkedstack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

LinkedStack* createLinkedStack()
{
	LinkedStack *stack;

	stack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (!stack)
		return (NULL);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *pNode;

	if (!pStack)
		return (FALSE);
	pNode = (StackNode *)malloc(sizeof(pNode));
	if (!pNode)
		return (FALSE);
	*pNode = element;
	pNode->pLink = pStack->pTopElement;
	pStack->pTopElement = pNode;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode popLS(LinkedStack* pStack)
{//고민
	StackNode pReturn;
	StackNode *pDel;

	if (!pStack)
		exit (1);
	if (pStack->currentElementCount == 0)
		exit(1);
	pReturn = *(pStack->pTopElement);
	pReturn.pLink = NULL;
	pDel = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	free(pDel);
	pStack->currentElementCount--;
	return pReturn;
}

StackNode* peekLS(LinkedStack* pStack)
{
	StackNode *pReturn;

	if (!pStack)
		return NULL;
	if (pStack->currentElementCount == 0)
		return (NULL);
	pReturn = pStack->pTopElement;
	return (pReturn);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	if (!pStack)
		return ;
	while (pStack->currentElementCount > 0)
		popLS(pStack);
	pStack->currentElementCount = 0;
}

int isLinkedStackFull(LinkedStack* pStack)
{

}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return NULL;
	return (pStack->currentElementCount == 0);
}

