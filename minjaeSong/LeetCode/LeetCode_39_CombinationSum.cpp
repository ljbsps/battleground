vector<vector<int>> answer;
vector<int> ans;
set<string> ss;

void dfs(int idx, int sum, vector<int>& ans, vector<int>& candidates, int target) {
    if (sum > target) {
        return;
    }
    if (sum == target) {
        vector<int> tmp;
        for (int elem : ans)
            tmp.push_back(elem);
        sort(tmp.begin(), tmp.end());
        string s;
        for (int i = 0; i < tmp.size(); i++) {
            s.append(to_string(tmp[i]));
        }
        if (ss.find(s) == ss.end()) {
            ss.insert(s);
            answer.push_back(tmp);
        }
        return;
    }
    for (int i = 0; i < candidates.size(); i++) {
        // 방문 o
        if (sum + candidates[i] <= target) {
            ans.push_back(candidates[i]);
            dfs(i, sum + candidates[i], ans, candidates, target);
            ans.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        answer.clear();
        ans.clear();
        ss.clear();
        dfs(0, 0, ans, candidates, target);
        return answer;
    }
};