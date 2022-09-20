class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int other = upper_bound(nums.begin() + i, nums.end(), target - nums[i]) - nums.begin() - 1;
            
            if (nums[other] == target - nums[i]) return {i+1, other+1};
        }   
        
        return {-1, -1};
    }
};