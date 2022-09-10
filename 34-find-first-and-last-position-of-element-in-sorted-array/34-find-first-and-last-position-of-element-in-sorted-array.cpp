class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>::iterator lower, upper;
        lower = lower_bound(nums.begin(), nums.end(), target);
        upper = upper_bound(nums.begin(), nums.end(), target);
        
        int low = lower - nums.begin();
        if (!nums.size() || low >= nums.size() || nums[low] != target) return {-1, -1};
        
        return {low, (int)(upper - nums.begin() - 1)};
    }
};