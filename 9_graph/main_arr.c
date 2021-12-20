#include <stdio.h>
#include <stdlib.h>
#include "arraygraph.h"

int main ()
{
	ArrayGraph* pGraph1;
	ArrayGraph* pGraph2;
	ArrayGraph* pGraph3;

	pGraph1 = createArrayGraph(6);
	pGraph2 = createArrayDirectedGraph(6);
	pGraph3 = createArrayDirectedGraph(6);

	for(int i = 0; i < 6; i++){
		addVertexAG(pGraph1, i);
		addVertexAG(pGraph2, i);
		addVertexAG(pGraph3, i);
	}
	addEdgeAG(pGraph1, 0, 1);
	addEdgeAG(pGraph1, 1, 2);
	addEdgeAG(pGraph1, 0, 2);
	addEdgeAG(pGraph1, 2, 3);
	addEdgeAG(pGraph1, 3, 4);
	addEdgeAG(pGraph1, 3, 5);
	addEdgeAG(pGraph1, 4, 5);

	addEdgeAG(pGraph2, 0, 1);
	addEdgeAG(pGraph2, 1, 2);
	addEdgeAG(pGraph2, 2, 1);
	addEdgeAG(pGraph2, 2, 0);
	addEdgeAG(pGraph2, 2, 3);
	addEdgeAG(pGraph2, 3, 2);
	addEdgeAG(pGraph2, 4, 5);
	addEdgeAG(pGraph2, 3, 4);
	addEdgeAG(pGraph2, 5, 3);

	addEdgewithWeightAG(pGraph3, 0, 1, 4);
	addEdgewithWeightAG(pGraph3, 1, 2, 1);
	addEdgewithWeightAG(pGraph3, 2, 1, 3);
	addEdgewithWeightAG(pGraph3, 2, 0, 2);
	addEdgewithWeightAG(pGraph3, 2, 3, 2);
	addEdgewithWeightAG(pGraph3, 3, 2, 1);
	addEdgewithWeightAG(pGraph3, 4, 5, 1);
	addEdgewithWeightAG(pGraph3, 3, 4, 1);
	addEdgewithWeightAG(pGraph3, 5, 3, 2);

	printf("G1: 무방향 그래프\n");
	displayArrayGraph(pGraph1);
	printf("\nG2: 방향 그래프 \n");
	displayArrayGraph(pGraph2);
	printf("\nG3: 방향 가중 그래프\n");
	displayArrayGraph(pGraph3);
}

