class Solution{
	int ret = 0;


public:
	int romanToInt(string s) {
		int tmp;

		for (int idx = 0; idx < s.length(); idx++)
		{
			tmp = charToInt(s[idx]);

			if (idx != s.length() - 1 && tmp < charToInt(s[idx + 1]))
				ret -= tmp;
			else
				ret += tmp;
		}

		return ret;
	}

	int charToInt(char c)
	{
		int convert = 0;

		switch (c)
		{
		case 'I':
			convert = 1;
			break;
		case 'V':
			convert = 5;
			break;
		case 'X':
			convert = 10;
			break;
		case 'L':
			convert = 50;
			break;
		case 'C':
			convert = 100;
			break;
		case 'D':
			convert = 500;
			break;
		case 'M':
			convert = 1000;
			break;
		}

		return convert;
	}
};
