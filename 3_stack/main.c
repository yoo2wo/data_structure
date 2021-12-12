#include <stdio.h>
#include "linkedstack.h"

int main()
{
	StackNode a;
	LinkedStack *c;

	c = createLinkedStack();
	a.data = '1';
	pushLS(c, a);
	a.data = '2';
	pushLS(c, a);
	a.data = '3';
	pushLS(c, a);
	a.data = '4';
	pushLS(c, a);
	popLS(c);
	popLS(c);
	// printf("%c\n", popLS(c)->data);
	// printf("%c\n", popLS(c)->data);
	deleteLinkedStack(c);
	popLS(c);
	// printf("%c\n", popLS(c)->data);
}
