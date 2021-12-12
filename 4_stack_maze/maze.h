#ifndef MAZE_H
#define MAZE_H

#include "linkedstack.h"

#define HEIGHT 8
#define WIDTH 8

typedef struct MapPosition {
	int x;
	int y;
}	MapPosition;

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);
StackNode getNextPos(StackNode temp);
int existNext(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH], StackNode nextPos);

#endif
