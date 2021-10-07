/*
10.2 Group Anagrams: Write a method to sort an array ot strings so that all tne anagrnms are next to 
each other. 
/*

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

int main()
{
	vector<string> s = { "abc", "df", "bca", "oip","rt", "fd", "pio", "cab" };
	int len = s.size();
	map<string, list<string>> anig;
	for (int i = 0; i < len; i++)
	{
		string sw = s[i];
		sort(sw.begin(), sw.end());
		if (anig.count(sw))
		{
			anig[sw].push_back(s[i]);
		}
		else {
			anig.insert({ s[i], {} });
		}
	}

	for (auto x : anig) {

		cout << x.first << "\n";
		for (auto y : x.second)
		{
			cout << y << "\n";
		}
	}
	return 0;
}
