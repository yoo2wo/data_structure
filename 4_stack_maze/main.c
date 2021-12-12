#include "maze.h"
#include <stdio.h>

int main()
{ //세로 Height, 가로 Width
	int mazeArray[HEIGHT][WIDTH] = {
		{0,0,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,0,1,1,1,1},
		{1,1,1,0,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,0}
	};
	MapPosition startPos;
	MapPosition endPos;
	LinkedStack *pStack;

	pStack = createLinkedStack();

	startPos.x = 0;
	startPos.y = 0;

	endPos.x = 7;
	endPos.y = 7;

	printMaze(mazeArray);
	findPath(mazeArray, startPos, endPos, pStack);
	return (0);

}
