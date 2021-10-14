#include <iostream>
using namespace std;

/*
2.3 Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node.
EXAMPLE
lnput:the node c from the linked list a->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a ->b->d->e->f.

בגלל שמקבלים גישה רק לאיבר ספציפי, אי אפשר למחוק אותו כי אין גישה לאיבר לפניו
אז מה נעשה זה נחליף את הדאטה של האיבר שקיבלנו עם האיבר לפניו, ונמחק את האיבר לפניו.
*/

struct Node {
	int data;
	Node* next;
};

void deleteMiddleNode(Node* mid);
void freeNodes(Node* listNode);

int main()
{
	Node* listNode = new Node;
	listNode->data = 3;
	listNode->next = new Node;
	listNode->next->data = 4;
	listNode->next->next = new Node;
	listNode->next->next->data = 8;
	listNode->next->next->next = new Node;
	listNode->next->next->next->data = 5;
	listNode->next->next->next->next = NULL;

	Node* curr = listNode->next->next;
	deleteMiddleNode(curr);

	freeNodes(listNode);
	return 0;
}

void deleteMiddleNode(Node* mid)
{
	Node* nextMid = mid->next;
	if (nextMid == NULL)
	{
		cout << "Error";
		return;
	}
	
	mid->data = nextMid->data;
	Node* nextPoint = nextMid->next;
	mid->next = nextPoint;
	nextMid->next = NULL;
	free(nextMid);
}

void freeNodes(Node* listNode)
{
	if (listNode == NULL)
		return;

	freeNodes(listNode->next);

	free(listNode);
}
