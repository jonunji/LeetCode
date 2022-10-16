class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        
        int n = nums.size(), m = 2 * sum + 1;        
        int dp[m][n];
        
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 0;
            
            dp[i][0] += i-sum == -nums[0];
            dp[i][0] += i-sum == nums[0];
        }
        
        for (int j = 1; j < n; j++)
            for (int i = -sum; i <= sum; i++)
            {
                int s = i + sum, 
                    neg = s - nums[j], 
                    pos = s + nums[j];
                
                dp[s][j] = 0;
                
                if (pos < m)  dp[s][j] += dp[pos][j-1];
                if (neg >= 0) dp[s][j] += dp[neg][j-1];
                
                if (i == target && j == n-1) return dp[s][j];
            }
        
        return dp[target + sum][n-1];
    }
};