class Solution {
private:
	int** map;
	int ret;

public:
	int getAnswer(int** input, int numWood) {
		map = input;

		ret = divideSearch(0, numWood - 1);

		return ret;
	}

	int getLength(int col)
	{
		int ret = 0, row = 9999;

		while (map[row][col] == 1)
		{
			ret++;
			row--;
		}

		return ret;
	}

	int divideSearch(int sCol, int eCol)
	{
		int ret, ret1, ret2;
		int s1, s2, e1, e2;
		int mid = (sCol + eCol) / 2;

		if (sCol == eCol) return getLength(sCol);

		s1 = sCol;
		s2 = mid + 1;
		e1 = mid;
		e2 = eCol;

		ret1 = divideSearch(s1, e1);
		ret2 = divideSearch(s2, e2);
		ret = ret1 > ret2 ? ret1 : ret2;

		int len1 = getLength(mid);
		int len2 = getLength(mid + 1);
		int common = len1 > len2 ? len2 : len1;
		int size = 2 * common;

		for (int idx = 10000 - common; idx < 10000; idx++)
		{
			bool left = true, right = true;
			int subSize = 2 * (10000 - idx), step = 1;

			while (left || right)
			{
				if (left)
				{
					if (mid > sCol && map[idx][mid - step] == 1) subSize += (10000 - idx);
					else left = false;
				}
				if (right)
				{
					if ((mid + 1) < eCol && map[idx][mid + 1 + step] == 1) subSize += (10000 - idx);
					else right = false;
				}
				step++;
			}
			size = size > subSize ? size : subSize;
		}
		ret = ret > size ? ret : size;		

		return ret;
	}
};

int main()
{
	Solution sol;

	while (1)
	{
		int* ans;
		int C, N;

		cin >> C;
		ans = (int*)malloc(C * sizeof(int));
		for (int nCase = 0; nCase < C; nCase++)
		{
			int** map;
			map = (int**)malloc(10000 * sizeof(int*));
			vector<int> wood;

			cin >> N;
			for (int i = 0; i < N; i++)
			{
				int inp;
				cin >> inp;
				wood.push_back(inp);
			}
			for (int i = 0; i < 10000; i++)
			{
				map[i] = (int*)malloc(N * sizeof(int));
			}

			int col = 0;
			for (vector<int>::iterator it = wood.begin(); it != wood.end(); it++)
			{
				for (int init = 0; init < (*it); init++)
				{
					map[9999 - init][col] = 1;
				}
				col++;
			}
			ans[nCase] = sol.getAnswer(map, N);
		}

		for (int cnt = 0; cnt < C; cnt++)
			cout << ans[cnt] << endl;
	}

	return 0;
}
