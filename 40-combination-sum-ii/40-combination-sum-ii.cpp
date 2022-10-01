class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) 
    {
        vector<int> curr;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        backtrack(nums, target, curr, res, 0);
        
        return res;
    }
    
    void backtrack(vector<int>& nums, int target, vector<int> curr, vector<vector<int>>& res, int start)
    {
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }
        
        // sum is too large
        if (target < 0) return;
        
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i-1]) continue;
            
            curr.push_back(nums[i]);
            backtrack(nums, target - nums[i], curr, res, i+1);            
            curr.pop_back();
        }
    }
};


// 1 1 2 5 6 7 10
// 116 125 