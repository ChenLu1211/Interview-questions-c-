#include <iostream>
#include <list>
using namespace std;

/*
2.2 Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

2 פויינטרים
בהתחלה שניהם מאותחלים לראש הרשימה, לאחר מכן פויינטר אחד הולך קיי צעדים
ואז שניהם מתקדמים צעד צעד עד שהפויינטר הראשון מגיע לסוף הרשימה
והפויינטר השני הוא זה שמצביע על האיבר הקיי
*/


void kFromLast(list<int> &findKth, int k);

int main()
{
	int k = 9;
	list<int> findKth = { 1, 3, 6, 8, 9, 2, 1, 8 };
	kFromLast(findKth, k);

	return 0;
}

void kFromLast(list<int>& findKth, int k)
{
	auto first = findKth.cbegin();
	auto second = findKth.cbegin();

	for (int i = 0; i < k & first != findKth.end(); i++)
	{
		first++;
	}

	if (first != findKth.end())
	{
		while (first != findKth.end())
		{
			first++;
			second++;
		}

		cout << *second << " : is the Kth element. ";
		return;
	}

	cout << "Error ";
}


