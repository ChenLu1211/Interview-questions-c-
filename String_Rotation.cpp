#include <iostream>
#include <string>
using namespace std;

/*
1.9 String Rotation: Assume you have a method i 5Su b 5 tr ing which checks if one word is a substring
of another. Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one
call to i5Sub5tring (e.g., "waterbottle" is a rotation of"erbottlewat").

הטריק הוא להבין שאם הן באותו אורך ולוקחים אחת מהן וכופלים אותה ב2 - 
אז אם השנייה היא תת מחרוזת שלה, אז היא בטוח רוטציה שלה.
חןלו , לוחן -> חןלוחןלו
*/


bool stringRotation(string s1, string s2);
bool isSubstring(string s1, string isSub);

int main()
{
	string s1 = "abcde";
	string s2 = "deabf";
	bool isRotate = stringRotation(s1, s2);
	cout << isRotate;

	return 0;
}


bool stringRotation(string s1, string s2)
{
	if (s1.length() == s2.length() && s1.length() > 0)
	{
		string dubStr = s1 + s1;

		return isSubstring(dubStr, s2);
	}

	else {
		return false;
	}
}

bool isSubstring(string s1, string isSub)
{
	if (s1.find(isSub) != string::npos)
	{
		return true;
	}
	return false;
}

