
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
1.3 URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (example : Input: "Mr John Smith ", 13   | Output: "Mr%20John%20Smith" )

- firstly count the white spaces,
then move from point that we need from the end ,
to start and swap the chars to the end until find space and repace with' % 2 0 ' (3 chars)
*/

void replaceSpaces(string str, int len);

int main()
{
	string str; int len;
	getline(cin, str);
	cin>>len;
	replaceSpaces(str, len);
	
	return 0;
}

void replaceSpaces(string str, int len)
{
	int countSpaces = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			countSpaces++;
		}
	}
	if (countSpaces == 0)
	{
		return;
	}
	int newLen = len + countSpaces * 2;

	if (countSpaces == 1)
	{
		newLen = len + countSpaces +2 ;
	}
	str = str.substr(0, newLen);  //end of the string
	len--;
	for (int i = newLen-1; i > 0 && len >= 0; i--)
	{
		if (str[len] == ' ')
		{
			str[i] = '0';
			str[i - 1] = '2';
			str[i - 2] = '%';
			i = i - 2;
		}
		else {
			str[i] = str[len];
		}
		len--;
	}
	cout << str;

}
