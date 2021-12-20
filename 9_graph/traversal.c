#include "traversal_stack.h"
#include "traversal_que.h"
#include "arraygraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void traversal_BFS(ArrayGraph *pGraph, int node)
{
	int *visited;
	LinkedDeque *pDeque;
	DequeNode pNode;
	int i;

	pDeque = createLinkedDeque();
	visited = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
	memset(visited, 0, sizeof(int) * pGraph->maxVertexCount);

	pNode.data = node;
	visited[node] = 1;
	insertRearLD(pDeque, pNode);
	while (!isLinkedDequeEmpty(pDeque))
	{
		i = deleteFrontLD(pDeque).data;
		printf("%d ", i);
		for(int j = 0; j < pGraph->maxVertexCount; j++){
			if (pGraph->ppAdjEdge[i][j] >= 1 && visited[j] == 0){
				visited[j] = 1;
				pNode.data = j;
				insertRearLD(pDeque, pNode);
			}
		}
	}

}

//방문은 vertex가 2이다.
void traversal_DFS(ArrayGraph *pGraph, int node)
{
	int *visited;
	LinkedStack *pStack;
	StackNode pNode;
	int i;

	pStack = createLinkedStack();
	visited = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
	memset(visited, 0, sizeof(int) * pGraph->maxVertexCount);

	pNode.data = node;
	visited[node] = 1;
	pushLS(pStack, pNode);

	while(!isLinkedStackEmpty(pStack))
	{
		i = popLS(pStack)->data;
		printf("%d ", i);
		for(int j = 0; j < pGraph->maxVertexCount; j++){
			if (pGraph->ppAdjEdge[i][j] >= 1 && visited[j] == 0)
			{
				visited[j] = 1;
				pNode.data = j;
				pushLS(pStack, pNode);
			}
		}
	}
}


int main()
{
	ArrayGraph* pGraph1;

	pGraph1 = createArrayGraph(8);


	for(int i = 0; i < 8; i++){
		addVertexAG(pGraph1, i);
	}

	addEdgeAG(pGraph1, 0, 1);
	addEdgeAG(pGraph1, 0, 2);
	addEdgeAG(pGraph1, 1, 3);
	addEdgeAG(pGraph1, 1, 4);
	addEdgeAG(pGraph1, 3, 7);
	addEdgeAG(pGraph1, 4, 5);
	addEdgeAG(pGraph1, 2, 5);
	addEdgeAG(pGraph1, 2, 6);

	printf("DFS: ");
	traversal_DFS(pGraph1, 0);
	printf("\n");

	printf("BFS: ");
	traversal_BFS(pGraph1, 0);
	printf("\n");
}


