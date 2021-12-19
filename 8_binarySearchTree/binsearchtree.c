#include <stdio.h>
#include "binsearchtree.h"

/*
key 는 유일
root의 key는 왼쪽 서브트리의 어떠한 key보다도 크다
삽입이 leaf에서만 일어난다.
검색에 유리

inorder로 출력시 크기순으로 나온다.
*/

BinSearchTree* createBinSearchTree()
{
	BinSearchTree *pBinSearchTree;
	BinSearchTreeNode *pRootNode;

	pBinSearchTree = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	pRootNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (!pBinSearchTree)
		return (NULL);
	pBinSearchTree->pRootNode = pRootNode;
	pBinSearchTree->pRootNode->key = 0;
	pBinSearchTree->pRootNode->pLeftChild = NULL;
	pBinSearchTree->pRootNode->pRightChild = NULL;
	return (pBinSearchTree);
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{
	BinSearchTreeNode *pTreeNode;
	BinSearchTreeNode *temp;

	if (!pBinSearchTree)
		return 0;
	if (searchRecursiveBST(pBinSearchTree, element.key, 0))
		return 0;
	pTreeNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	*pTreeNode = element;
	if(!pTreeNode)
		return (0);
	temp = searchRecursiveBST(pBinSearchTree, element.key, 1);
	if (temp->key > element.key)
		temp->pLeftChild = pTreeNode;
	else
		temp->pRightChild = pTreeNode;
	return (1);
}

int deleteElementBST(BinSearchTree* pBinSearchTree, int key)
{
	BinSearchTreeNode *temp;
	int tempKey;

	if (!pBinSearchTree)
		return (0);
	if (searchRecursiveBST(pBinSearchTree, key, 0))
		return 0;
	temp = searchRecursiveBST(pBinSearchTree, key, 0);
	tempKey = temp->key;
	if (!temp->pLeftChild || !temp->pRightChild){
		if(!temp->pLeftChild && !temp->pRightChild){
			free(temp);
		}
		free(temp);
		searchRecursiveBST(pBinSearchTree, key, 1)->key = tempKey;
	}



}
//flag : 0 => 일반 찾기, flag : 1 => 없다면 그전 노드 찾기
BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key, int flag)
{
	BinSearchTreeNode *pReturn;

	if (!pBinSearchTree || !pBinSearchTree->pRootNode)
		return NULL;
	if (pBinSearchTree->pRootNode->key == key){
		pReturn = pBinSearchTree->pRootNode;
		return pReturn;
	}
	if (pBinSearchTree->pRootNode->key > key){
		if (!pBinSearchTree->pRootNode->pLeftChild && flag == 1)
			return (pBinSearchTree->pRootNode);
		pBinSearchTree->pRootNode = pBinSearchTree->pRootNode->pLeftChild;
		searchRecursiveBST(pBinSearchTree, key, flag);
	}
	else {
		if (!pBinSearchTree->pRootNode->pRightChild && flag == 1)
			return (pBinSearchTree->pRootNode);
		pBinSearchTree->pRootNode = pBinSearchTree->pRootNode->pRightChild;
		searchRecursiveBST(pBinSearchTree, key, flag);
	}
}

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{
	if (!pTreeNode)
		return NULL;
	if (pTreeNode->key == key)
		return (pTreeNode);
	if(pTreeNode->pLeftChild->key > key)
		searchInternalRecursiveBST(pTreeNode->pLeftChild, key);
	else
		searchInternalRecursiveBST(pTreeNode->pRightChild, key);
}

// BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key)
// {

// }


void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{
	BinSearchTreeNode* pNode;

	if(!pBinSearchTree)
		return ;
	deleteBinSearchTreeNode(pBinSearchTree->pRootNode);
	free(pBinSearchTree);
	pBinSearchTree = NULL;
}

void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode)
{
	if (!pTreeNode)
		return ;
	deleteBinTreeNode(pTreeNode->pLeftChild);
	deleteBinTreeNode(pTreeNode->pRightChild);
	free(pTreeNode);
	pTreeNode = NULL;
}
