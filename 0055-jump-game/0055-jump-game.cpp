class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size(), end = min(nums[0], n-1);
        if (n <= 1) return true;
        
        bool dp[n];
        for (int i = 0; i < n; i++) dp[i] = false;
        
        for (int i = 0; i <= end; i++)
        {
            int pos = min(i + nums[i], n-1);
                
            dp[pos] = true;
            end = max(pos, end);
        }
        
        return dp[n-1];
    }
};