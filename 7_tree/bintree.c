#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *pBinTree;
	BinTreeNode *pRootNode;

	pBinTree = (BinTree *)malloc(sizeof(BinTree));
	pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!pBinTree)
		return (NULL);
	pBinTree->pRootNode = pRootNode;
	pBinTree->pRootNode->data = rootNode.data;
	pBinTree->pRootNode->visited = 0;
	pBinTree->pRootNode->pLeftChild = NULL;
	pBinTree->pRootNode->pRightChild = NULL;

	return (pBinTree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *pNode;

	if (!pParentNode)
		return (NULL);
	pNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!pNode)
		return (NULL);
	pParentNode->pLeftChild = pNode;
	*pNode = element;
	pNode->visited = 0;
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	return (pNode);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *pNode;

	if (!pParentNode)
		return (NULL);
	pNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!pNode)
		return (NULL);
	pParentNode->pRightChild = pNode;
	*pNode = element;
	pNode->visited = 0;
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	return (pNode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	pNode->pLeftChild->visited = 1;
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	pNode->pRightChild->visited = 1;
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	//후위순회
	BinTreeNode* pNode;

	if(!pBinTree)
		return ;
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
	pBinTree = NULL;
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
	pNode = NULL;
}
