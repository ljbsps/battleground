class Solution {
public:
    bool visit[5] = {false, };
    int cnt = 0;
    void dfs(int idx, int num, int n){
        // 기저
        if (idx == n) {
            cnt++;
            return;
        }
        for (int i = num; i < 5; i++) {
            dfs(idx + 1, i, n);
        }
    }
    
    int countVowelStrings(int n) {
        dfs(0,0,n);
        return cnt;
    }
};