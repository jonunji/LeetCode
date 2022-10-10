class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        int curMin, curMax, res;
        
        res = *max_element(nums.begin(), nums.end());
        curMin = curMax = 1;
        
        for (int i = 0; i < n; i++)
        {
            int prodMax = nums[i] * curMax;
            int prodMin = nums[i] * curMin;
            
            curMax = max({prodMax, prodMin, nums[i]});
            curMin = min({prodMax, prodMin, nums[i]});
            
            res = max(res, curMax);
        }
        
        return res;
    }
};