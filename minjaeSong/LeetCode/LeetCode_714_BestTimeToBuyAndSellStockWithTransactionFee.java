class Solution {
    public int maxProfit(int[] prices, int fee) {
        //dp[i][j]: i번째 까지 j=0(산 상태), 1(판 상태) 고려했을 때 최대 profit 
        int length = prices.length;
        int dp[][] = new int[length][2];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i=1;i<=length-1;i++){
            dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = Math.max(dp[i-1][0] + prices[i] - fee, dp[i-1][1]);
        }
        int ans = Math.max(dp[length-1][0], dp[length-1][1]);
        return (ans>0) ? ans : 0;
    }
}