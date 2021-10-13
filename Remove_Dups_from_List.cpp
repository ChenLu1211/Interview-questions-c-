#include <iostream>
#include <set>
using namespace std;

/*
2.1 Remove Dups: Write code to remove duplicates from an unsorted linked list.

ניצור מבנה נתונים SET
נעבור על הרשימה, ונכניס את איברים למבנה הנתונים,
ברגע שאיבר כבר קיים, נמחוק אותו מהרשימה ונמשיך.
O(N)
*/


void removeDups(list<int> &removeDup);

int main()
{
	list<int> removeDup = { 1, 3, 6, 8, 9, 2, 1, 8 };
	removeDups(removeDup);

	return 0;
}

void removeDups(list<int>& removeDup)
{
	set<int> mySet;

	for (auto itr = removeDup.cbegin(); itr != removeDup.end(); itr++)
	{
		if (mySet.count(*itr))
		{
			removeDup.erase(itr--);
		}

		else {
			mySet.insert(*itr);
		}
	}
}
