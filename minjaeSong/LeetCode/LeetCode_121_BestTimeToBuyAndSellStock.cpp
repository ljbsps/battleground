class Solution {
public:
    int maxProfit(vector<int>& prices) {    
        int size = prices.size();
        int mini = INT_MAX, ans = 0;         
        for(int i=0;i<size;i++){
            if(prices[i] < mini)
                mini = prices[i];
            else if (prices[i] - mini > ans)
                ans = prices[i] - mini;
        }
        return ans;
    }
};