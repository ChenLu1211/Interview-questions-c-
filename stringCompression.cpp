#include <iostream>
#include <string>
using namespace std;

/*
1.6 String Compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).

- create vector of chars, then for loop on the given string -> when a char is change, insert the count and the next char to the vector
then return the shorter string. O(N)
*/

void stringCompression(string str);

int main()
{
	string str;
	cin >> str;
	if (str.length() > 1) {
		stringCompression(str);
	}
	else {
		cout << str;
	}
	return 0;
}

void stringCompression(string str)
{	
	int len = str.length();
	int count = 1;
	char first = str[0];
	vector<char> newStr;
	newStr.push_back(first);

	for (int i = 0; i < len && len > newStr.size() ; i++)
	{
		if (str[i] != first)
		{
			string s = to_string(count);
			char const* pchar = s.c_str();
			newStr.push_back(*pchar);
			newStr.push_back(str[i]);

			first = str[i];
			count = 1;
		}
		else {
			count++;
		}
	}
	string s = to_string(count);
	char const* pchar = s.c_str();
	newStr.push_back(*pchar);

	if (newStr.size() > len)
	{
		cout << str;
	}
	else {
		for (auto x : newStr)
		{
			cout << x;
		}
	}
}
