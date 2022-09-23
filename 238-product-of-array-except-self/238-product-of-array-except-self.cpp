class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res(nums.size(), 1);
        
        for (int i = 0, pre = 1, suf = 1; i < nums.size(); i++)
        {
            // Calculate the prefix
            res[i] *= pre;
            pre *= nums[i];
            
            // Calculate the suffix
            res[nums.size() - i - 1] *= suf;
            suf *= nums[nums.size() - i - 1];
        } 
        
        return res;
    }
};