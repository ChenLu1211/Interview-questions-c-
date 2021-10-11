/*
1.1 Check if a string that contains only lowercase a-z letters has no repetitive letters
will check with bit manipulation
*/

int main()
{
	string str = "adbrvythv";
	bool isUn = isUnique(str);
	cout << isUn;
	
	return 0;
}

bool isUnique(string str)
{
	int mask = 0; // int - 32 bit is enough
	int num, isDup;
	int len = str.length();

	for (int i = 0; i < len; i++)
	{
		num = str[i] - 'a'; // to ASCII
		isDup = mask & (1 << num);
		if (isDup > 0)
		{
			return false;
		}
		mask |= (1 << num);
	}
	return true;
}
