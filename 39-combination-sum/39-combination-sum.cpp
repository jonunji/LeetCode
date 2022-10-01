class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, curr);
        
        return res;
    }
    
    void backtrack(vector<int>& nums, int target, int start, vector<int> curr)
    {
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }
        
        if (target < 0) return;
        
        for (int i = start; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, curr);
            curr.pop_back();
        }
    } 
};