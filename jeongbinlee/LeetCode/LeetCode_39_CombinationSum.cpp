class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates);
        vector<int> cand;

        
        for (int startIdx = 0; startIdx < candidates.size(); startIdx++)
        {
            int sum = 0, i = startIdx, nextIdx = startIdx + 1, sub = 0;

            do
            {
                if (sum < target)
                {
                    sum += candidates[i];
                    cand.push_back(candidates[i]);
                }
                else {
                    if (sum == target)
                    {
                        ret.push_back(cand);
                    }
                    sub = cand.back();
                    sum -= sub;
                    cand.pop_back();
                    i++;
                    if (i == candidates.size())
                    {
                        if (cand.size() == 0) break;
                        do
                        {
                            sub = cand.back();
                            sum -= sub;
                            cand.pop_back();
                            nextIdx = FindNext(candidates, sub);
                        } while (i == nextIdx && cand.size() > 0);
                        i = nextIdx;
                        if (i >= candidates.size())
                            break;
                    }
                }
            }
            while (cand.size() != 0);

            if (cand.size() != 0)
            {
                int size = cand.size();
                for (int clear = 0; clear < size; clear++)
                {
                    cand.pop_back();
                }
            }
        }
        
        return ret;
	}

    int FindNext(vector<int> vec, int value)
    {
        int ret = 0;

        for (int idx = 0; idx < vec.size(); idx++)
        {
            if (vec[idx] == value)
            {
                ret = idx;
                break;
            }
        }

        return ++ret;
    }

	void sort(vector<int>& candidate)
    {
        int temp = 0;
        for (int i = 0; i < candidate.size(); i++)
        {
            int j = i;
            while (j > 0 && candidate[j - 1] > candidate[j])
            {
                temp = candidate[j];
                candidate[j] = candidate[j - 1];
                candidate[j - 1] = temp;
                --j;
            }
        }
    }
};
