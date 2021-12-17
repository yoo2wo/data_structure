#include "traversal.h"
#include "bintree.h"
#include <stdio.h>

int main()
{
	BinTree *pBinTree;
	BinTreeNode *node[13];
	BinTreeNode pNode;

	pNode.data = 'A';
	pBinTree = makeBinTree(pNode);

	node[0] = getRootNodeBT(pBinTree);
	pNode.data = 'B';
	node[1] = insertLeftChildNodeBT(node[0], pNode);
	pNode.data = 'C';
	node[2] = insertRightChildNodeBT(node[0], pNode);
	pNode.data = 'D';
	node[3] = insertLeftChildNodeBT(node[1], pNode);
	pNode.data = 'E';
	node[4] = insertRightChildNodeBT(node[1], pNode);
	pNode.data = 'F';
	node[5] = insertLeftChildNodeBT(node[2], pNode);
	pNode.data = 'G';
	node[6] = insertRightChildNodeBT(node[2], pNode);
	pNode.data = 'H';
	node[7] = insertLeftChildNodeBT(node[3], pNode);
	pNode.data = 'I';
	node[8] = insertRightChildNodeBT(node[3], pNode);
	pNode.data = 'J';
	node[9] = insertLeftChildNodeBT(node[4], pNode);
	pNode.data = 'K';
	node[10] = insertRightChildNodeBT(node[5], pNode);
	pNode.data = 'L';
	node[11] = insertLeftChildNodeBT(node[6], pNode);
	pNode.data = 'M';
	node[12] = insertRightChildNodeBT(node[6], pNode);

	printf("전위 순회 : ");
	preorderTraversalBinTree(node[0]);
	printf("\n");
	printf("중위 순회 : ");
	inorderTraversalBinTree(node[0]);
	printf("\n");
	printf("후위 순회 : ");
	postorderTraversalBinTree(node[0]);
	printf("\n");
	return 0;
}
