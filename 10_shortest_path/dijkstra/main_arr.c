#include <stdio.h>
#include <stdlib.h>
#include "arraygraph.h"
#define INF 1000
/*
다익스트라 : 하나의 정점에서 다른 모든 정점으로의 최단 경로
	선형 탐색 : O(N^2)
	최소힙 사용 : O(NlogN)
플로이드 : 모든 정점에서 모든 정점으로의 최단 경로

*/
int getShortest(int *d, int *visit, ArrayGraph* pGraph)
{
	int min = INF;
	int vertex = 0;

	for(int i = 0; i < pGraph->maxVertexCount; i++){
		if (d[i] < min && !visit[i]){
			min = d[i];
			vertex = i;
		}
	}
	return (vertex);
}

void dijkstra(int start, ArrayGraph* pGraph)

	int visit[6] = {0, 0, 0, 0, 0, 0};
	int d[6] = {INF, INF, INF, INF, INF, INF};// 수정 필요
	int current;

	for(int i = 0; i < pGraph->maxVertexCount; i++){
		if (pGraph->ppAdjEdge[start][i] > 0)
			d[i] = pGraph->ppAdjEdge[start][i];
	}
	d[start] = 0;
	visit[start] = 1;
	for(int i = 0; i < pGraph->maxVertexCount - 2; i++){
		current = getShortest(d, visit, pGraph);
		visit[current] = 1;
		for(int j = 0; j < pGraph->maxVertexCount; j++){
			if (!visit[j] && pGraph->ppAdjEdge[current][j] != 0)// 방문 안한 노드중 연결 current와 연결되어있어야한다.
				if (d[current] + pGraph->ppAdjEdge[current][j] < d[j]) //j로 가는데 current를 경유하는게 더빠르다면 교체
					d[j] = d[current] + pGraph->ppAdjEdge[current][j];
		}
	}
	printf("dijkstra : ");
	for(int i=0; i < pGraph->maxVertexCount; i++){
		printf("%d ", d[i]);
	}
}

int main ()
{
	ArrayGraph* pGraph1;

	pGraph1 = createArrayGraph(6);

	for(int i = 0; i < 6; i++){
		addVertexAG(pGraph1, i);
	}
	addEdgewithWeightAG(pGraph1, 0, 1, 1);
	addEdgewithWeightAG(pGraph1, 1, 2, 2);
	addEdgewithWeightAG(pGraph1, 0, 2, 4);
	addEdgewithWeightAG(pGraph1, 2, 3, 1);
	addEdgewithWeightAG(pGraph1, 3, 4, 8);
	addEdgewithWeightAG(pGraph1, 3, 5, 3);
	addEdgewithWeightAG(pGraph1, 4, 5, 4);

	printf("G1: 무방향 가중 그래프\n");
	displayArrayGraph(pGraph1);

	printf("--------\n");
	dijkstra(0, pGraph1);
}


