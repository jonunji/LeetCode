class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        
        backtrack(nums, curr, res, 0);
        
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int> curr, vector<vector<int>>& res, int start)
    {
        res.push_back(curr);
        
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i-1]) continue;
                
            curr.push_back(nums[i]);
            backtrack(nums, curr, res, i+1);
            curr.pop_back();
        }
    }
};
