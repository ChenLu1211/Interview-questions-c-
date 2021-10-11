#include <iostream>
#include <string>
using namespace std;

/*
Palindrome Permutation: Given a string, write a function to check if it is a permutation of
a palindrome.
EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat'; "atco eta·; etc.)

- using dictionary -first insert <char, val> , then check: for length > 2:
if the length is odd -> need to be only one char with odd val 
if the length is even -> all the key should be with even value.
*/

bool isPalindrome(string str);
bool isPermoOfPalindrome(string str);

int main()
{
	string str;
	getline(cin, str);
	//isPalindrome(str);
	isPermoOfPalindrome(str);

	return 0;
}

bool isPalindrome(string str)
{	
	int len = str.length() - 1;
	
	for (int i = 0; i <= len; i++)
	{
		if (str[i] != str[len])
		{
			return false;
		}
		len--;
	}
}

bool isPermoOfPalindrome(string str)
{
	int len = str.length();
  if (len == 1)
      return true;
  if (len == 2)
  {
    if(str[0] == str[1])
      return true;
    else
      return false;
  }
  
	map<char, int> premo;
	for (int i = 0; i < len; i++)
	{
		if (premo.count(str[i]))
		{
			premo[str[i]]++;
		}
		else {
			premo[str[i]] = 1;
		}
	}
	int countOdd = 0;
	for (auto val : premo)
	{
		if (val.second % 2 != 0)
		{
			countOdd++;
			if (countOdd > 1 || len % 2 == 0)
			{
				return false;
			}
		}
	}
	return true;
}
