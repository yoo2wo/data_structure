#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

typedef struct BinSearchTreeNodeType
{
	int key;
	char value;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BinSearchTreeNode;

typedef struct BinSearchTreeType
{
	BinSearchTreeNode *pRootNode;
} BinSearchTree;

BinSearchTree* createBinSearchTree();
int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element);
int deleteElementBST(BinSearchTree* pBinSearchTree, int key);

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key, int flag);
BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key);
BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key);

void deleteBinSearchTree(BinSearchTree* pBinSearchTree);
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
