#include <stdio.h>
#include "arrayHeap.h"
#include "linkedgraph.h"
#include "linkedlist.h"
#define INF 1000

void displayArrayHeap(ArrayHeap* pArrayHeap)
{
	if (pArrayHeap != NULL) {
		for (int i = 1; i <= pArrayHeap->currentElementCount; i++) {
			printf("[%d]: %d\n", i, pArrayHeap->pElement[i].key);
		}
	}
}

void dijkstra(int start, LinkedGraph *pGraph)
{
	int visit[6] = {0, 0, 0, 0, 0, 0};
	int d[6] = {INF, INF, INF, INF, INF, INF};// 수정 필요
	int cur;
	int distance;
	int next;
	int nextDist;
	int i = 0;

	ArrayHeap *pArrayHeap;
	HeapNode node;
	HeapNode *tNode;
	ListNode *nextNode;

	d[start] = 0;
	pArrayHeap = createArrayHeap(getEdgeCountLG(pGraph));
	node.to = start;
	node.key = 0;
	insertHeapNode(pArrayHeap, node);
	while(pArrayHeap->currentElementCount > 0)
	{
		tNode = deleteHeapNode(pArrayHeap);
		cur = tNode->to;
		distance = tNode->key * -1;

		if (d[cur] < distance)
			continue;
		nextNode = pGraph->ppAdjEdge[i]->headerNode.pLink;
		for(int j = 0; j < pGraph->ppAdjEdge[i]->currentElementCount; j++){
			next = nextNode->data.vertexID;
			nextDist = distance + nextNode->data.weight;
			printf("[%d] -> next:%d, nDist:%d, dist:%d\n",i, next, nextDist, distance);
			nextNode = nextNode->pLink;
			if (d[next] > nextDist)
			{
				d[next] = nextDist;
				node.key = nextDist * -1;
				node.to = next;
				insertHeapNode(pArrayHeap, node);
			}
			for(int i=0; i < pGraph->maxVertexCount; i++){//
				printf("%d ", d[i]);
			}//
			printf("\n");//
			printf("-----\n");
		}
		i++;
	}

	printf("dijkstra : ");
	for(int i=0; i < pGraph->maxVertexCount; i++){
		printf("%d ", d[i]);
	}
}

int main()
{
	LinkedGraph* pGraph1;

	pGraph1 = createLinkedGraph(6);

	for(int i = 0; i < 6; i++){
		addVertexLG(pGraph1, i);
	}
	addEdgewithWeightLG(pGraph1, 0, 1, 1);
	addEdgewithWeightLG(pGraph1, 1, 2, 2);
	addEdgewithWeightLG(pGraph1, 0, 2, 4);
	addEdgewithWeightLG(pGraph1, 2, 3, 1);
	addEdgewithWeightLG(pGraph1, 3, 4, 8);
	addEdgewithWeightLG(pGraph1, 3, 5, 3);
	addEdgewithWeightLG(pGraph1, 4, 5, 4);

	dijkstra(0, pGraph1);
}


