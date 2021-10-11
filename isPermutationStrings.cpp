#include <iostream>
#include <string>
using namespace std;

/*
Given two strings, write a method to decide if one is a permutation of the
other.
with space- hash \ bucket (128 -ASCII)
without space- mergesort \ bubble
I will use hash -> multi-set.
*/

bool isPermutation(string first, string second);

int main()
{
	string first, second;
	cin >> first >> second;
	if (isPermutation(first, second)) {
		cout<< "True";
	}
	else {
		cout<<"False";
	}
	
	return 0;
}

bool isPermutation(string first, string second)
{
	if (first.length() != second.length()) {
		return false;
	}
	int len = first.length();

	multiset<char> myStr;
	for (int i = 0; i < len; i++)
	{
		myStr.insert(first[i]);
	}

	for (int j = 0; j < len; j++)
	{
		if (myStr.count(second[j]))
		{
			myStr.erase(myStr.find(second[j]));
		}
		else {
			return false;
		}
	}
	return true;
}
