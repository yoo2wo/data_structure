#include <stdio.h>
#include <stdlib.h>
#include "arraygraph.h"
#define INF 1000
#define NUMBER 6
/*
다익스트라 : 하나의 정점에서 다른 모든 정점으로의 최단 경로
플로이드 : 모든 정점에서 모든 정점으로의 최단 경로
	거쳐가는 노드를 하나씩 추가한다.
	2차원 배열을 사용한다.
	동적 프로그래밍을 사용한다.

*/

void floyd(ArrayGraph* pGraph)
{
	int d[NUMBER][NUMBER];

	for(int i = 0; i < NUMBER; i++){
		for(int j = 0; j < NUMBER; j++){
			if (i != j && pGraph->ppAdjEdge[i][j] == 0)
				d[i][j] = INF;
			else
				d[i][j] = pGraph->ppAdjEdge[i][j];
		}
	}

	// for(int i = 0; i < NUMBER; i++){
	// 	for(int j = 0; j < NUMBER; j++){
	// 		printf("%d ",d[i][j]);
	// 	}
	// 	printf("\n");
	// }

	//k 는 거쳐가는 노드
	for(int i = 0; i < NUMBER; i++){
		for(int j = 0; j < NUMBER; j++){
			for(int k = 0; k < NUMBER; k++){
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for(int i = 0; i < NUMBER; i++){
		for(int j = 0; j < NUMBER; j++){
			printf("%2d ",d[i][j]);
		}
		printf("\n");
	}
}

int main ()
{
	ArrayGraph* pGraph1;
	int *d;

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
	floyd(pGraph1);
}


