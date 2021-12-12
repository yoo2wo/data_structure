#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	StackNode curPos;
	int forwarded;
	curPos.pos.x = startPos.x;
	curPos.pos.y = startPos.y;
	while (1)
	{
		mazeArray[curPos.pos.x][curPos.pos.y] = VISITED;
		if (curPos.pos.x == endPos.x && curPos.pos.y == endPos.y){
			printf("경로 찾음\n");
			break;
		}
		forwarded = FALSE;
		for (int dir = 0; dir < 4; dir++){
			if (movable(curPos, dir, mazeArray)){
				pushLS(pStack, curPos);
				curPos = move(curPos, dir);
				forwarded = TRUE;
				break;
			}
		}
		if (forwarded != TRUE)
		{
			mazeArray[curPos.pos.x][curPos.pos.y] = BACKTRACKED;
			if (pStack->currentElementCount <= 0){
				printf("길 없음\n");
				break;
			}
			curPos = popLS(pStack);
		}
		printf("--------\n");
		printMaze(mazeArray);
	}
}

int movable(StackNode pos, int dir, int mapArray[HEIGHT][WIDTH])
{
	StackNode next = move(pos, dir);
	if (next.pos.x < 0 || next.pos.y < 0 || next.pos.x >= HEIGHT || next.pos.y >= WIDTH)
		return (0);
	if (mapArray[next.pos.x][next.pos.y] != 0)
		return (0);
	return (1);
}

StackNode move(StackNode pos, int dir)
{
	StackNode next;

	int offset[4][2] = {
		{-1,0},
		{0,1},
		{1,0},
		{0,-1}
	};

	next.pos.x = pos.pos.x + offset[dir][0];
	next.pos.y = pos.pos.y + offset[dir][1];
	return next;
}

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int i = 0;
	int j = 0;

	while (i < HEIGHT)
	{
		printf("[");
		while (j < WIDTH)
		{
			printf("%d ",mazeArray[i][j]);
			j++;
		}
		printf("]\n");
		i++;
		j = 0;
	}
}

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
