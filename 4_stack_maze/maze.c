#include "maze.h"
#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 0 1 2 3 : 오른쪽 부터 시계방향

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	StackNode curPos;
	StackNode nextPos;
	int isFound = FALSE;

	curPos.dir = 0;
	curPos.xPos = startPos.x;
	curPos.yPos = startPos.y;
	curPos.pLink = NULL;
	nextPos.pLink = NULL;
	nextPos.dir = 0;

	pushLS(pStack, curPos);
	while (pStack->currentElementCount > 0 && isFound == FALSE)
	{
		curPos = popLS(pStack);
		while (isFound == FALSE && curPos.dir < 4)
		{
			nextPos = getNextPos(curPos);
			if (existNext(pStack, mazeArray,nextPos)){
				curPos.dir++;
				pushLS(pStack, curPos);
				mazeArray[curPos.yPos][curPos.xPos] = 2;
				curPos = nextPos;
				curPos.dir = 0;
				printf("---------\n");
				printMaze(mazeArray);
				if (curPos.xPos == endPos.x && curPos.yPos == endPos.y){
					isFound = TRUE;
					curPos.dir = 0;
					pushLS(pStack, curPos);
					mazeArray[nextPos.yPos][nextPos.xPos] = 2;
				}
			} else {
				curPos.dir++;
			}
		}
	}
}

// {
// 	StackNode curPos;
// 	StackNode nextPos;

// 	curPos.dir = 0;
// 	curPos.xPos = startPos.x;
// 	curPos.yPos = startPos.y;
// 	curPos.pLink = NULL;
// 	nextPos.pLink = NULL;
// 	nextPos.dir = 0;

// 	pushLS(pStack, curPos);
// 	mazeArray[curPos.yPos][curPos.xPos] = 2;
// 	printf("1--------\n");
// 	while (pStack->currentElementCount > 0)
// 	{
// 		if (curPos.xPos == endPos.x && curPos.yPos == endPos.y){
// 			printf("도착\n");
// 			return ;
// 		}
// 		printf("2--------\n");
// 		while (curPos.dir < 4)
// 		{
// 			nextPos = getNextPos(curPos);
// 			if (existNext(pStack, mazeArray, nextPos)){
// 				pushLS(pStack, nextPos);
// 				curPos = nextPos;
// 				curPos.dir = 0;
// 				mazeArray[curPos.yPos][curPos.xPos] = 2;
// 				break;
// 			} else {
// 				curPos.dir++;
// 			}
// 		}
// 		if (!existNext(pStack, mazeArray, nextPos)){
// 			curPos = popLS(pStack);
// 			curPos.dir++;
// 		}
// 		printMaze(mazeArray);
// 	}
// 	printf("종료, 경로 없음.\n");
// }
// {
// 	StackNode curPos;
// 	StackNode nextPos;

// 	curPos.dir = 0;
// 	curPos.xPos = startPos.x;
// 	curPos.yPos = startPos.y;
// 	curPos.pLink = NULL;
// 	nextPos.pLink = NULL;
// 	nextPos.dir = 0;

// 	pushLS(pStack, curPos);
// 	mazeArray[curPos.yPos][curPos.xPos] = 2;
// 	while (pStack->currentElementCount > 0)
// 	{
// 		curPos = popLS(pStack);
// 		if (curPos.xPos == endPos.x && curPos.yPos == endPos.y){
// 			printf("도착\n");
// 			return ;
// 		}
// 		while (curPos.dir < 4)
// 		{
// 			nextPos = getNextPos(curPos);
// 			if (existNext(pStack, mazeArray, nextPos)){
// 				pushLS(pStack, nextPos);
// 				curPos = nextPos;
// 				curPos.dir = 0;
// 				mazeArray[curPos.yPos][curPos.xPos] = 2;
// 				break;
// 			} else {
// 				curPos.dir++;
// 			}
// 		}
// 		printMaze(mazeArray);
// 		printf("--------\n");
// 	}
// 	printf("종료, 경로 없음.\n");
// }

StackNode getNextPos(StackNode temp)
{
	if (temp.dir == 0)
		temp.xPos += 1;
	else if (temp.dir == 1)
		temp.yPos += 1;
	else if (temp.dir == 2)
		temp.xPos -= 1;
	else if (temp.dir == 3)
		temp.yPos -= 1;
	temp.pLink = NULL;
	return (temp);
}

// int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
// {

// }
// void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
// {

// }
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

int existNext(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH], StackNode nextPos)
{
	//이동할 노드가 범위를 벗어남
	if (nextPos.xPos > WIDTH || nextPos.xPos < 0)
		return (0);
	if (nextPos.yPos > HEIGHT || nextPos.yPos < 0)
		return (0);
	//다음 위치가 벽일 경우
	if (mazeArray[nextPos.yPos][nextPos.xPos] == 1)
		return (0);
	if (mazeArray[nextPos.yPos][nextPos.xPos] == 2)
		return (0);
	return (1);
}


