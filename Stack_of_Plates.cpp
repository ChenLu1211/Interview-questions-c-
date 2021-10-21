#include <iostream>
#include <algorithm>
using namespace std;

/*
3.3 Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
composed of several stacks and should create a new stack once the previous one exceeds capacity.
SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack
(that is, pop () should return the same values as it would if there were just a single stack).

FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific substack.
המימוש של הפולאו אפ - זה לשרשר אחורה את המחסניות, אם הוצאתי ממחסנית שהיא לא אחרונה:
אז להוציא איבר מהמסחנית שאחריה ולהכניס אותו אלייה
אם המחסנית שלפניה התרוקנה- למחוק אותה.
( לא מימשתי כאן את POPAT)

*/

#define MAX_CAPACITY 4

struct Stack {
protected:
	int *arr = new int[MAX_CAPACITY];
	int top = 0;

public:
	void pop() {

		if (top > 0) {
			arr[top-1] = -1;
			top--;
		}
		else {
			cout << "Error - Empty Stack" << endl;
		}
	}
	void push(int data)
	{
		if (top < MAX_CAPACITY)
		{
			arr[top] = data;
			top++;
		}
	}

};

struct SetOfStacks {
protected:
	vector<Stack*> stacks;
	int values = 0;

public:
	void pop() {

		if ( values > 0) {
			values % MAX_CAPACITY == 0 ? stacks[values/MAX_CAPACITY - 1]->pop() : stacks[values / MAX_CAPACITY]->pop();				
			values--;
			if (values % MAX_CAPACITY == 0)
			{
				stacks.pop_back();
			}
		}
		else {
			cout << "Error - Empty Stack" << endl;
		}
	}

	void push(int data)
	{
		if (values % MAX_CAPACITY == 0)
		{
			Stack* newStack = new Stack;
			stacks.push_back(newStack);
			newStack->push(data);
		}		
		else {
			stacks[(values / MAX_CAPACITY )]->push(data);
		}
		values++;
	}
};

int main()
{
	SetOfStacks* stacks = new SetOfStacks;
  for(int i=0; i< 9; i++)
  {
    stacks->push(i);
	}
  
	stacks->pop();
	stacks->pop();
	stacks->pop();
	stacks->pop();

	free(stacks);
	return 0;
}
