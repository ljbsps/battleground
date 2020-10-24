class Solution {
public:
	int climbStairs(int n) {
		int num1 = n, num2 = 0;
		double temp = 0;
		int ret = 0;

		do
		{
			if (num1 == 0 || num2 == 0)
			{
				temp++;
			}
			else
			{
				temp += (fact(num1 + num2) / fact(num1)) / fact(num2);
			}
			num1 = num1 - 2;
			num2++;
		} while (num1 >= 0);

		ret = (int)temp;
		return ret;
	}

	double fact(int n)
	{
		double ret = 1;

		for (int i = 0; i < n; i++)
		{
			ret *= (n - i);
		}

		return ret;
	}
};