#include <stdio.h>
#include "doublylist.h"
/*
노드 접근 : O(n)
노드 탐색 : O(n)
삽입, 삭제 : O(1)
실제 노드 삽입,삭제 : O(n)

이중 연결리스트가 적당한 자료구조는 덱(deque : double-ended queue)이다.
(덱은 양쪽으로 삽입 삭제가 가능한 큐 이다.)

장점
1.탐색할때 단순연결리스트는 최악의 경우 노드 전체를 탐색하지만
  양방향 연결 리스트는 절반으로 줄어든다.
2.노드를 탐색할때 양방향으로 탐색할수있다.
단점
1.이전노드의 주소를 저장하기위해 변수가 하나더 사용된다.
2.구현시 단순연결리스트보다 복잡하다.
*/
int main(){
	DoublyList *pList = NULL;
	DoublyListNode node;

	pList = createDoublyList();
	if (!pList)
		return 0;
	node.data = 2;
	addDLElement(pList, 0, node);
	node.data = 4;
	addDLElement(pList, 1, node);
	node.data = 6;
	addDLElement(pList, 2, node);
	node.data = 8;
	addDLElement(pList, 0, node);
	displayDoublyList(pList);
	removeDLElement(pList, 0);
	displayDoublyList(pList);
	deleteDoublyList(pList);
	displayDoublyList(pList);
	return 0;
}
