class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size(), end = min(nums[0], n-1);
        
        for (int i = 0; i <= end; i++)
        {
            int pos = min(i + nums[i], n-1);
            if (pos == n-1) return true;
            
            end = max(pos, end);
        }
        
        return false;
    }
};