class Solution {
public:
	int nextGreaterElement(int n) {
		string str = to_string(n);
		deque<int> value;
		int ret = 0, digit, pivot = -1, next;
		bool isSwap = false;

		if (n / 10 == 0) return -1;

		digit = str.length();

		for (int pos = digit - 1; pos >= 0; pos--)
		{
			value.push_back(str[pos] - 48);
			if (pos == 0) return -1;

			if (str[pos] > str[pos - 1])
			{
				pivot = pos - 1;
				break;
			}
		}
		if (pivot == -1) return -1;
		sort(value.begin(), value.end());
		for (int swap = 0; swap < value.size(); swap++)
		{
			if (value[swap] > str[pivot] - 48)
			{
				int temp = str[pivot] - 48;
				str[pivot] = value[swap];
				value[swap] = temp;
				isSwap = true;
				break;
			}
		}
		if (!isSwap) return -1;

		for (int pos = 0; pos < digit; pos++)
		{
			if (pos <= pivot)
				if (str[pos] - 48 >= 0)
				{
					if (ret + (str[pos] - 48) * pow(10, digit - 1 - pos) >= INT_MAX) return -1;
					ret += (str[pos] - 48) * pow(10, digit - 1 - pos);
				}
				else
				{
					if (ret + str[pos] * pow(10, digit - 1 - pos) >= INT_MAX) return -1;
					ret += str[pos] * pow(10, digit - 1 - pos);
				}
			else
			{
				if (ret + (value[pos - pivot - 1]) * pow(10, digit - 1 - pos) >= INT_MAX) return -1;
				ret += (value[pos - pivot - 1]) * pow(10, digit - 1 - pos);
			}
		}

		return ret;
	}
};
