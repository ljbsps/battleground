class Solution {
    public int coinChange(int[] coins, int amount) {
        // dp[i]: fewest num of coins for amount i
        int dp[] = new int[amount+1];
        for(int i=0;i<=amount;i++)
            dp[i] = 10001;
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int idx=0;idx<coins.length;idx++){
                if(i-coins[idx]>=0)   
                    dp[i] = Math.min(dp[i-coins[idx]]+1, dp[i]);
            }
        }
        return (dp[amount]==10001)? -1 : dp[amount];
    }
}