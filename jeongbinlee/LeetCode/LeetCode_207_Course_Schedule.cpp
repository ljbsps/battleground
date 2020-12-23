class Solution {
	vector<vector<int>> tree;
	int** cache;
	int* isCheck;
	int totalNum;

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int next = 0;
		bool ret = true;

		totalNum = numCourses;
		tree = prerequisites;

		if (prerequisites.empty() || tree.size() == 1)
			return true;

		cache = (int**)malloc(totalNum * sizeof(int*));
		for (int init = 0; init < totalNum; init++)
		{
			cache[init] = (int*)malloc(totalNum * sizeof(int));
		}

		for (int idx = 0; idx < tree.size(); idx++)
		{
			vector<int> route;

			isCheck = (int*)malloc(totalNum * sizeof(int));
			memset(isCheck, -1, totalNum * sizeof(int));

			if (!dfs(idx, true)) return false;
		}

		return ret;
	}

	int findNext(int key)
	{
		for (int idx = 0; idx < tree.size(); idx++)
		{
			if (tree.at(idx).at(0) == key)
			{
				return idx;
			}
		}

		return -1;
	}

	bool dfs(int curIdx, bool isCacheUse = false)
	{
		int idx, cur, next;
		bool ret;

		cur = tree.at(curIdx).at(0);
		next = tree.at(curIdx).at(1);

		if (isCheck[cur] == 1 || isCheck[next] == 1) return false;

		if(isCacheUse) if(cache[cur][next] == 1) return true;
		isCheck[cur] = 1;

		cache[cur][next] = 1;
		idx = findNext(next);
		if (idx == -1)
		{
			return true;
		}
		ret = dfs(idx);

		return ret;
	}
};
