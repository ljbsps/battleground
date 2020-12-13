class Solution {
public:
    bool go(int target, vector<vector<int>>& cond, int* visit, int* cache) {
        bool res = false;
        // 기저
        if (cond[target].size() == 0) {
            return false;
        }
        if (cache[target] == 1) return false;
        for (int i = 0; i < cond[target].size(); i++) {
            if (visit[cond[target][i]]) return true;            
            if (cache[target]==-1) {
                visit[target] = true;
                if (res = go(cond[target][i], cond, visit, cache))
                    cache[target] = 1;
                visit[target] = false;
            }
        }        
        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> condition(numCourses);
        int visit[100000] = { 0, };
        int cache[100000];
        memset(cache, -1, 100000 * sizeof(int));
        for (int i = 0; i < prerequisites.size(); i++) {
            condition[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {       
            if (cache[i] != -1) continue;
            if (go(i,condition, visit, cache))
                return false;            
        }
        return true;
    }
};