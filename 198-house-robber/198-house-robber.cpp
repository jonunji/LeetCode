class Solution {
public:
    
    vector<int> memo;
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        memo = vector<int>(n, -1);
        
        return rob(nums, n - 1);
    }
    
    int rob(vector<int>& nums, int i)
    {
        if (i < 0) return 0;
        
        if (memo[i] >= 0) return memo[i]; 
        
        memo[i] = max(nums[i] + rob(nums, i-2), rob(nums, i-1));
        return memo[i];
    }
};