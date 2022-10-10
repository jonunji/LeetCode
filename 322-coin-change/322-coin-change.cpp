class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for (int i = 0; i <= amount; i++)
            for (int c : coins)
                if (c <= i) dp[i] = min(dp[i], 1 + dp[i - c]);
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
//     int coinChange(vector<int>& coins, int amount, vector<int>& memo)
//     {
//         if (amount < 0) return -1;
//         if (amount == 0) return 0;
        
//         // return if we have seen this before
//         if (memo[amount] > 0) return memo[amount]; 
        
//         int n = coins.size(), count = amount + 1;
//         for (int i = 0; i < n; i++)
//         {
//             int c = coinChange(coins, amount - coins[i], memo);
//             if (c >= 0) count = min(count, c);
//         }
                          
//         return memo[amount] = count > amount ? -1 : count + 1;
//     }
};