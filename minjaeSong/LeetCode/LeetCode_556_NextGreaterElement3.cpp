class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> vec, vec2;
        int tmp = n, cnt = 0;
        while (tmp != 0) {
            vec.push_back(tmp % 10);
            tmp /= 10;
            cnt++;
        }
        for (int i = vec.size() - 1; i >= 0; i--) {
            vec2.push_back(vec[i]);
        }
        long ans = 0;
        do {
            ans = 0;
            for (int i = 0; i < cnt; i++){
                ans = ans * 10 + vec2[i];
                if(ans>INT_MAX) 
                    return -1;
            }
            if (ans > n) break;
        } while (next_permutation(vec2.begin(), vec2.end()));
        return ans == n ? -1 : ans;
    }
};