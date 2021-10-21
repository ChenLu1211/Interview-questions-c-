#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
2.6 Palindrome: Implement a function to check if a linked list is a palindrome.

מקבלים גישה לראש הרשימה,
אם יש אפשרות לזיכרון נוסף , נכניס חצי רשימה (בעזרת 2 פויינטרים מהיר ואיטי) לתוך מחסנית
ואת חצי השני של הרשימה נבדוק בעזרת הוצאה מהמחסנית והשוואה.
אם אין אפשרות לזיכרון נוסף -> נשלח פויינטר עד לסוף הרשימה, ואז נדע את אורך הרשימה, ונשווה
2 פויינטרים עד האמצע אחד בהתחלה ואחד בסוף

/* Push elements from first half of linked list onto stack. When fast runner
(which is moving at 2x speed) reaches the end of the linked list, then we
know we're at the middle*
כעת נממש עם המחסנית.
*/

struct Node {
	int data;
	Node* next;
};

bool isPalindrome(Node* head);
void freeNodes(Node* listNode);

int main()
{
	Node* listNode = new Node;
	listNode->data = 3;
	listNode->next = new Node;
	listNode->next->data = 4;
	listNode->next->next = new Node;
	listNode->next->next->data = 4;
	listNode->next->next->next = new Node;
	listNode->next->next->next->data = 3;
	listNode->next->next->next->next = NULL;
	
	isPalindrome(listNode);

	freeNodes(listNode);
	return 0;
}

bool isPalindrome(Node* head)
{
	if (head == NULL)
	{
		cout << "Error";
		return false;
	}
	if (head->next == NULL)
	{
		return true;
	}
	
	Node* firstPointer = head;
	Node* secondPointer = head;
	stack<int> myStack;

	while (secondPointer!=NULL && secondPointer->next!= NULL)
	{
		myStack.push(firstPointer->data);
		firstPointer = firstPointer->next;
		secondPointer = secondPointer->next->next;
	}

	// odd len -> skip the middle
	if (secondPointer != NULL)
	{
		firstPointer = firstPointer->next;
	}


	for (int i = 0; i <= myStack.size() && firstPointer!=NULL ; i++)
	{
		int tops = myStack.top();
		if (tops != firstPointer->data)
		{
			return false;
		}
		myStack.pop();
		firstPointer = firstPointer->next;
	}

	return true;

}

void freeNodes(Node* listNode)
{
	if (listNode == NULL)
		return;

	freeNodes(listNode->next);

	free(listNode);
}

