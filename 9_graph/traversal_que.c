#include <stdlib.h>
#include <stdio.h>
#include "arraygraph.h"
#include "traversal_que.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *pQueue;

	pQueue = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	if (!pQueue){
		printf("메모리 할당 오류, createLinkedDeque\n");
		return (NULL);
	}
	pQueue->currentElementCount = 0;
	pQueue->pFrontNode = NULL;
	pQueue->pRearNode = NULL;
	return (pQueue);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *pNode;

	if (!pDeque)
		exit(1);
	pNode = (DequeNode *)malloc(sizeof(DequeNode));
	if (!pNode)
		exit(1);
	*pNode = element;
	pNode->pLLink = NULL;
	pNode->pRLink = NULL;

	if (pDeque->currentElementCount == 0){
		pDeque->pFrontNode = pNode;
		pDeque->pRearNode = pNode;
		//pNode->pLLink = pDeque;
		pDeque->currentElementCount++;
		return (TRUE);
	}
	pNode->pRLink = pDeque->pFrontNode;
	pNode->pRLink->pLLink = pNode;
	pDeque->pFrontNode = pNode;
	//pNode->pLLink = pDeque;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *pNode;

	if (!pDeque)
		exit(1);
	pNode = (DequeNode *)malloc(sizeof(DequeNode));
	if (!pNode)
		exit(1);
	*pNode = element;
	pNode->pLLink = NULL;
	pNode->pRLink = NULL;
	if (pDeque->currentElementCount == 0){
		pDeque->pFrontNode = pNode;
		pDeque->pRearNode = pNode;
		//pNode->pLLink = pDeque;
		pDeque->currentElementCount++;
		return (TRUE);
	}
	pNode->pLLink = pDeque->pRearNode;
	pNode->pLLink->pRLink = pNode;
	pDeque->pRearNode = pNode;
	//pNode->pRLink = pDeque;
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode pReturn;

	if (!pDeque)
		exit(1);
	pReturn = *(pDeque->pFrontNode);
	pReturn.pLLink = NULL;
	pReturn.pRLink = NULL;
	if (pDeque->currentElementCount < 2){
		free(pDeque->pFrontNode);
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
		pDeque->currentElementCount--;
		return(pReturn);
	}
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	free(pDeque->pFrontNode->pLLink);
	pDeque->currentElementCount--;
	return (pReturn);
}

DequeNode deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *temp;
	DequeNode pReturn;

	if (!pDeque)
		exit(1);
	temp = pDeque->pRearNode;
	pReturn = *temp;
	pReturn.pLLink = NULL;
	pReturn.pRLink = NULL;
	if (pDeque->currentElementCount < 2){
		free(temp);
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
		pDeque->currentElementCount--;
		return (pReturn);
	}
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	//pDeque->pRearNode->pRLink = pDeque;
	free(temp);
	pDeque->currentElementCount--;
	return (pReturn);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (NULL);
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	while (pDeque->currentElementCount <= 0)
		deleteFrontLD(pDeque);
	free(pDeque);
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
	if (pDeque->currentElementCount > 0)
		return (TRUE);
	return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (pDeque->currentElementCount <= 0)
		return (TRUE);
	return (FALSE);
}

void displayDeque(LinkedDeque *pDeque)
{
	DequeNode temp;
	int i = 0;

	printf("-------\n");
	temp = *(pDeque->pFrontNode);
	while (1){
		printf("[%d] : %c\n", i, temp.data);
		i++;
		if (i == pDeque->currentElementCount)
			break;
		temp = *(temp.pRLink);
	}
	printf("-------\n");
	return ;
}

