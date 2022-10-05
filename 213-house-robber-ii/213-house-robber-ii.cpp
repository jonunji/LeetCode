class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) return n ? nums[0] : 0;
        
        return max(rob(nums, 0, n-1), rob(nums, 1, n));
    }
    
    int rob(vector<int>& nums, int start, int end) 
    {
        int prev = 0, curr = 0;
        
        for (int i = start; i < end; i++)
        {
            int temp = max(prev + nums[i], curr);
            
            prev = curr;
            curr = temp;
        }
        
        return curr;
    }
};