int main()
{
	string str = "adbrvythv";
	bool isUn = isUnique(str);
	cout << isUn;
	
	return 0;
}

bool isUnique(string str)
{
	int mask = 0, num, isDup;
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
