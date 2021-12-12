#include "traversal.h"
#include <stdio.h>

void	preorderTraversalBinTree(BinTreeNode* pNode) // v L R
{
	if (!pNode)
		return ;
	pNode->visited = 1;
	printf("%c ",pNode->data);
	preorderTraversalBinTree(pNode->pLeftChild);
	preorderTraversalBinTree(pNode->pRightChild);
	return ;
}

void	inorderTraversalBinTree(BinTreeNode* pNode)	// L v R
{
	if (!pNode)
		return ;
	inorderTraversalBinTree(pNode->pLeftChild);
	pNode->visited = 1;
	printf("%c ",pNode->data);
	inorderTraversalBinTree(pNode->pRightChild);
	return ;
}

void	postorderTraversalBinTree(BinTreeNode* pNode) // L R v
{
	if (!pNode)
		return ;
	postorderTraversalBinTree(pNode->pLeftChild);
	postorderTraversalBinTree(pNode->pRightChild);
	pNode->visited = 1;
	printf("%c ",pNode->data);
	return ;
}
