class Solution {
	int ret;
	// 0 1 2 3 4
public:
	int countVowelStrings(int n) {
		int val[5];
		ret = 0;
		
		if (n == 1) return 5;
		for (int init = 0; init < 5; init++)
		{
			val[init] = 1;
		}

		for (int iter = 0; iter < n - 1; iter++)
		{
			for (int step = 1; step < 5; step++)
			{
				val[step] = val[step - 1] + val[step];
			}
			ret = val[0] + val[1] + val[2] + val[3] + val[4];
		}

		return ret;
	}
};
