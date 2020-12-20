class Solution {
	int ret;

public:
	int maxProfit(vector<int>& prices) {
		int min, max, minIdx, maxIdx;
		getMinMax(prices, 0, prices.size() - 1, minIdx, maxIdx, min, max);

		ret = getProfit(prices, minIdx, prices.size() - 1);

		return ret;
	}

	void getMinMax(vector<int>& prices, int ns, int ne, int& minIdx, int& maxIdx, int& min, int& max)
	{
		int nmin = -1, nmax = -1;
		for (int idx = ns; idx <= ne; idx++)
		{
			if (nmin == -1 || prices.at(idx) < nmin)
			{
				nmin = prices.at(idx);
				minIdx = idx;
			}
			if (prices.at(idx) > nmax && minIdx < idx)
			{
				nmax = prices.at(idx);
				maxIdx = idx;
			}
		}

		min = nmin;
		max = nmax;
	}

	int getProfit(vector<int>& prices, int ns, int ne)
	{
		int ret = 0, front;
		int nexts, nexte, min, max;
		int minIdx, maxIdx;
		if (ne <= 0) return 0;

		if (ns == ne)
		{
			getMinMax(prices, 0, ne - 1, minIdx, maxIdx, min, max);

			front = getProfit(prices, minIdx, ne - 1);
		}
		else
		{
			getMinMax(prices, ns, ne, minIdx, maxIdx, min, max);
			nexts = 0;
			nexte = minIdx - 1;
			front = getProfit(prices, nexts, nexte);
			if(minIdx < maxIdx)
				ret = max - min;
		}

		ret = ret > front ? ret : front;

		return ret;
	}
};
