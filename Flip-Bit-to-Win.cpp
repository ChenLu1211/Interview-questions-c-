#include <iostream>
#include <algorithm>
#include <ctime>
#include <bitset>
using namespace std;

/*
5.3 Flip Bit to Win: You have an integer and you can flip exactly one bit from a O to a 1. Write code to
find the length of the longest sequence of 1 s you could create.
example:
input: 1775 --> 11011101111
output: 8

solution:
1. save in array the binary representation (I wrote the both way to do that)
then move over all the numbers to check the longest sequence of 1s that can create by change one 0 to 1.

2. no space needed- logical shift on the given number to move over all the bits.

I will write the right shift.

*/

//----------------------------------------------------------//
void convertIntToBinary(unsigned int n)
{
	//first 
	vector<int> binaryNum;
	while (n / 2 != 0) {
		binaryNum.push_back(n % 2);
		n = n / 2;
	}
	binaryNum.push_back(n % 2);

	//second
	string binary = bitset<16>(n).to_string(); //to binary
	cout << binary << "\n";
}
//----------------------------------------------------------//

int FlipBit(int n);

int main()
{
	int n = 2764; //0101011001100
	cout<< FlipBit(n);

	return 0;
}

int FlipBit(int n)
{
	if (n == ~0) {
		return 32;
	}

	int currLen = 0;
	int prevLen = 0;
	int maxLen = 1;

	while (n != 0)
	{
		if ((n & 1) == 1) { //if the bit is 1
			currLen++;
		}
		else { //the bit is 0
			//will check the next bit - if equel to - 1 ,will continue counting, else - reset count;
			prevLen = ((n & 2) == 0) ? 0 : currLen;
			currLen = 0;
		}
		maxLen = max(maxLen, prevLen + currLen + 1);
		n = n >> 1;
	}

	return maxLen;
}



