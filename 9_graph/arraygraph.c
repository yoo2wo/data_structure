#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraygraph.h"

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;

	if (maxVertexCount <= 0)
		return (NULL);
	pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	pGraph->pVertex= (int *)malloc(sizeof(int) * maxVertexCount);
	pGraph->ppAdjEdge = (int **)malloc(sizeof(int*) * maxVertexCount);
	if (!pGraph || !pGraph->pVertex || !pGraph->ppAdjEdge){
		free(pGraph);
		free(pGraph->pVertex);
		free(pGraph->ppAdjEdge);
		return (NULL);
	}
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->currentVertexCount = 0;
	for(int i = 0; i < maxVertexCount; i++){
		pGraph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
		if (!pGraph->ppAdjEdge[i]){
			free(pGraph);
			free(pGraph->pVertex);
			free(pGraph->ppAdjEdge);
			return (NULL);
		}
	}
	memset(pGraph->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
	for (int i=0; i < maxVertexCount; i++){
		memset(pGraph->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
	}

	return (pGraph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;

	pGraph = createArrayGraph(maxVertexCount);
	if (!pGraph)
		return (NULL);
	pGraph->graphType = GRAPH_DIRECTED;
	return (pGraph);
}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)
		return ;
	for(int i = 0; i < pGraph->maxVertexCount; i++){
		free(pGraph->ppAdjEdge[i]);
	}
	free(pGraph->pVertex);
	free(pGraph->ppAdjEdge);
	free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph)
{
	if (!pGraph)
		return (1);
	return (!(pGraph->currentVertexCount > 0));
}
// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (FAIL);
	if (vertexID > pGraph->maxVertexCount)
		return (FAIL);
	if (pGraph->pVertex[vertexID] == USED){
		printf("이미 존재하는 vertex\n");
		return (FAIL);
	}
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED));
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, fromVertexID))
		return (FAIL);
	if (!checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (FAIL);
	if (vertexID > pGraph->maxVertexCount || !pGraph->pVertex[vertexID])
		return (FAIL);
	return (SUCCESS);
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, vertexID))
		return (FAIL);
	pGraph->pVertex[vertexID] = NOT_USED;
	for(int i = 0; i < pGraph->maxVertexCount; i++){
		removeEdgeAG(pGraph, i, vertexID);
		removeEdgeAG(pGraph, vertexID, i);
	}
	return (SUCCESS);
}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, fromVertexID))
		return (FAIL);
	if (!checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	return (SUCCESS);
}

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)
		return ;
	for(int i = 0; i < pGraph->maxVertexCount; i++){
		for(int j = 0; j < pGraph->maxVertexCount; j++){
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
}
