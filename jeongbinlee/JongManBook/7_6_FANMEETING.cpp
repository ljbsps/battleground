#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <deque>

using namespace std;

class Solution {
private:

public:
	int getAnswer(string strCele, string strFan) {
		deque<int> cele, fan;
		int ret = 0, iter;

		for (int i = 0; i < strCele.size(); i++)
		{
			if (strCele.at(i) == 'M') cele.push_back(1);
			else cele.push_back(0);
		}
		for (int i = 0; i < strFan.size(); i++)
		{
			if (strFan.at(i) == 'M') fan.push_back(1);
			else fan.push_back(0);
		}
		
		iter = fan.size() - cele.size() + 1;
		for (int rep = 0; rep < iter; rep++)
		{
			if(divideSearch(cele, fan, 0, cele.size() - 1) == 0) ret++;
			fan.pop_front();
		}

		return ret;
	}

	int divideSearch(deque<int> cele, deque<int> fan, int start, int end)
	{
		int ret, ret1, ret2, mid = (start + end) / 2;
		int s1, s2, e1, e2;

		if (start == end)
		{
			ret = cele.at(start) & fan.at(end);
			return ret;
		}

		s1 = start;
		e1 = mid;
		s2 = mid + 1;
		e2 = end;

		ret1 = divideSearch(cele, fan, s1, e1);
		ret2 = divideSearch(cele, fan, s2, e2);
		ret = ret1 + ret2;

		return ret;
	}
};

int main()
{
	Solution sol;

	int* ans;
	int C;

	cin >> C;
	ans = (int*)malloc(C * sizeof(int));
	for (int nCase = 0; nCase < C; nCase++)
	{
		string strCele, strFan;

		cin >> strCele >> strFan;

		ans[nCase] = sol.getAnswer(strCele, strFan);
	}

	for (int cnt = 0; cnt < C; cnt++)
		cout << ans[cnt] << endl;

	return 0;
}
