#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdlib.h>
#include <stdio.h>

typedef struct GraphVertexType
{
	int vertexID;
	int weight;
} GraphVertex;

typedef struct ListNodeType
{
	GraphVertex data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// ���� ����� ������ ����
	ListNode headerNode;		// ��� ���(Header Node)
} LinkedList;

LinkedList *createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode *getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
void displayList(LinkedList *pList);
void reverseLinkedList(LinkedList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
