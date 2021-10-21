#include <iostream>
#include <algorithm>
using namespace std;

/*
3.2 Stack Min: How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time.

שני מימושים:
אחד- עבור כל איבר שמכניסים לשמור מי המינימום עבורו
השני- לשמור עוד מחסנית של מינימום או רשימה מקושרת עם 'הקודם' של מינימומים

המימוש השני יהיה יותר יעיל מבחינת מקום אם האיברים שאנחנו מכניסים רובם לא בצורה יורדת
*/



struct Stack {
protected:
	int *arr = new int;
	int* minArr = new int;

	int top = 0;
	int minIndex = 0;

public:
	int minVal = INT_MIN;

	void pop() {

		if (top > 0) {
			if (minIndex > 0 && arr[top - 1] == minArr[minIndex - 1])
			{
				minIndex--;
				minVal = minArr[minIndex - 1];
			}
			arr[top-1] = -1;
			top--;
		}
		else {
			cout << "Error - Empty Stack" << endl;
		}
	}
	void push(int data)
	{
		if (top == 0)
		{
			minVal = data;
			minArr[minIndex] = minVal;
			minIndex++;
		}

		arr[top] = data;
		top++;

		if (data < minArr[minIndex-1])
		{
			minVal = data;
			minArr[minIndex] = minVal;
			minIndex++;
		}
	}

};

//void doMinStack();

int main()
{
	Stack* minStack = new Stack;
	minStack->push(5);
	minStack->push(7);

	cout << "minVal: " << minStack->minVal << endl;

	minStack->push(2);
	minStack->push(3);

	cout << "minVal: " << minStack->minVal << endl;

	minStack->push(6);
	minStack->push(1);

	cout << "minVal: " << minStack->minVal << endl;
	
	minStack->pop();

	cout << "minVal: " << minStack->minVal << endl;

	minStack->pop();
	minStack->pop();
	minStack->pop();
	minStack->pop();
	minStack->pop();
	minStack->pop();

	cout << "minVal: " << minStack->minVal << endl;

	free(minStack);
	return 0;
}
