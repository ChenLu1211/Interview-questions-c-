#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

/*
5.1 Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method
to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through
i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5
bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully
fit between bit 3 and bit 2.

פתרון:
תחילה אצור מסיכה של אחדים ואפסים בין איי לג'יי,
אח"כ בעזרת אנד ננקה את הביטים בין איי לג'יי באן
נזיז את אם להיות בין איי לג'יי, ע"י דחיפה של איי ביטים
ואז נעשה אור בין אם לאן

*/

void bitManip(int m, int n, int i, int j);

int main()
{
	int m = 56; //     0111000  
	int n = 2764; //0101011001100
	int i = 3;
	int j = 10;

	bitManip(m, n, i, j);
	return 0;
}

void bitManip(int m, int n, int i, int j)
{
	int mask = ~0; //all one
	int left = mask << (j + 1);
	int right = (1 << i) - 1;
	int res = left | right; //111j0----0i111

	int newN = n & res;
	int newM = m << i;

	int bitMan = m | n;
	cout << bitMan;
}


