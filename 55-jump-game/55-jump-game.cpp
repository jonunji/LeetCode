class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        if (nums.size() == 1) return true;
        int end = nums[0];
        
        for (int i = 0; i < nums.size() && i <= end; i++)
        {
            if (nums[i] + i >= nums.size() - 1) return true;
                
            end = max(i + nums[i], end);
        }
        
        return false;
    }
};