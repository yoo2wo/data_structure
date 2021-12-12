#ifndef MAZE_H
#define MAZE_H

#define HEIGHT 8
#define WIDTH 8
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

typedef struct MapPosition {
	int x;
	int y;
}	MapPosition;

typedef struct StackNodeType
{
	MapPosition pos;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;
	StackNode* pTopElement;
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);


void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);
int movable(StackNode pos, int dir, int mapArray[HEIGHT][WIDTH]);
StackNode move(StackNode pos, int dir);

#define TRUE		1
#define FALSE		0

#endif

