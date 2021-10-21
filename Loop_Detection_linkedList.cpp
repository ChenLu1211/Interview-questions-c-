#include <iostream>
#include <string>
using namespace std;

/*
2.8 Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C

two options to solve this problem:
1. hash -> when we get to the node that we allready visit, we will return it (O(n) + space O(n)) // or null if there is no loop.
2. fast pointer- slow pointer:
	when the pointers meeting we will return the slow to start and when they meet again (+1 pass ) this is the node.
	they always will be k steps from each other. = k steps from the loop node begin. (O(n) time)

	נממש את הפויינטרים
*/

struct Node {
	int data;
	Node* next;
};

void LoopList(Node* head);
void freeNodes(Node* listNode);

int main()
{
	Node* listNode = new Node;
	listNode->data = 3;
	listNode->next = new Node;
	listNode->next->data = 4;
	listNode->next->next = new Node;
	listNode->next->next->data = 5;
	listNode->next->next->next = listNode->next;   //new Node;
//	listNode->next->next->next->data = 3;
//	listNode->next->next->next->next = NULL;
	
	LoopList(listNode);

	freeNodes(listNode);
	return 0;
}

void LoopList(Node* head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	
	Node* fastPointer = head;
	Node* slowPointer = head;

	while (fastPointer!=NULL && fastPointer->next!= NULL)
	{
		slowPointer = slowPointer->next;
		fastPointer = fastPointer->next->next;

		if (slowPointer == fastPointer)
		{
			slowPointer = head;
			while (slowPointer != fastPointer)
			{
				slowPointer = slowPointer->next;
				fastPointer = fastPointer->next;
			}
			cout << "data:"<<slowPointer->data <<" addess: "<< slowPointer;
		}

	}

}

void freeNodes(Node* listNode)
{
	if (listNode == NULL)
		return;

	freeNodes(listNode->next);

	free(listNode);
}
