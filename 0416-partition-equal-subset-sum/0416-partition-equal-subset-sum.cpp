class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        sum /= 2;
        
        int dp[sum + 1]; memset(dp, false, sizeof(dp));
        dp[0] = true;
        
        for (int n : nums)
            for (int i = sum; i >= n; i--)
                if (dp[i - n]) 
                    dp[i] = true;
            
        return dp[sum];
    }
};
