#include <stdio.h>
#include "arrayHeap.h"
#include <stdlib.h>
#include "arraygraph.h"
#include "traversal_stack.h"
#include <string.h>
#define EDGE_NUM 7

/*
가장 적은 비용으로 모든 노드를 연결 => 최소 신장 트리 (MST)
간선을 거리가 짧은 순서대로 그래프에 포함시킨다.
	단 사이클을 만들면 안된다.

*/

void displayArrayHeap(ArrayHeap* pArrayHeap)
{
	if (pArrayHeap != NULL) {
		for (int i = 1; i <= pArrayHeap->currentElementCount; i++) {
			printf("[%d]: %d\n", i, pArrayHeap->pElement[i].key);
		}
	}
}

int traversal_DFS(ArrayGraph *pGraph, int node)
{
	int *visited;
	int *poped;
	LinkedStack *pStack;
	StackNode pNode;
	int i;

	pStack = createLinkedStack();
	visited = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
	poped = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
	memset(visited, 0, sizeof(int) * pGraph->maxVertexCount);
	memset(poped, 0, sizeof(int) * pGraph->maxVertexCount);

	pNode.data = node;
	visited[node] = 1;
	pushLS(pStack, pNode);

	while(!isLinkedStackEmpty(pStack))
	{
		i = popLS(pStack)->data;
		poped[i] = 1;
		// printf("%d ", i);
		for(int j = 0; j < pGraph->maxVertexCount; j++){
			if (pGraph->ppAdjEdge[i][j] >= 1 && visited[j] == 0)//pop한것과 연결된것 그리고 push된적 없는것
			{
				visited[j] = 1;
				pNode.data = j;
				pushLS(pStack, pNode);
			}
			else if(pGraph->ppAdjEdge[i][j] >= 1 && visited[j] == 1 && poped[j] == 0)
			{
				return (0);//사이클이 있다.
			}
		}
	}
	return (1);
}

void kruscal(ArrayGraph* pGraph)
{
	ArrayHeap *pArrayHeap;
	ArrayGraph *pGraph1;//
	HeapNode node;
	HeapNode *node2;
	int i = 0;

	pArrayHeap = createArrayHeap(EDGE_NUM);

	for(int i = 0; i < pGraph->maxVertexCount; i++){
		for(int j = 0; j < pGraph->maxVertexCount; j++){
			if (pGraph->ppAdjEdge[i][j] != 0 && i <= j){
				node.key = pGraph->ppAdjEdge[i][j] * -1;
				node.from = i;
				node.to = j;
				insertHeapNode(pArrayHeap, node);
			}
		}
	}

	pGraph1 = createArrayGraph(6);//추가 필요
	for(int i = 0; i < 6; i++){
		addVertexAG(pGraph1, i);
	}

	while (i < EDGE_NUM){
		node2 = deleteHeapNode(pArrayHeap);
		node2->key = node2->key * -1; //maxheap을 사용해서
		addEdgewithWeightAG(pGraph1, node2->from, node2->to, node2->key);
		if (traversal_DFS(pGraph1, 0) == 0)
			removeEdgeAG(pGraph1, node2->from, node2->to);
		i++;
	}
	displayArrayGraph(pGraph1);
}

int main()
{

	ArrayGraph* pGraph1;

	pGraph1 = createArrayGraph(6);

	for(int i = 0; i < 6; i++){
		addVertexAG(pGraph1, i);
	}
	addEdgewithWeightAG(pGraph1, 0, 1, 4);
	addEdgewithWeightAG(pGraph1, 1, 2, 2);
	addEdgewithWeightAG(pGraph1, 0, 2, 3);
	addEdgewithWeightAG(pGraph1, 2, 3, 1);
	addEdgewithWeightAG(pGraph1, 3, 4, 1);
	addEdgewithWeightAG(pGraph1, 3, 5, 5);
	addEdgewithWeightAG(pGraph1, 4, 5, 6);

	kruscal(pGraph1);
}
