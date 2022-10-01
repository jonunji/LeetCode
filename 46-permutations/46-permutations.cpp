class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, curr, res);
        
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int> curr, vector<vector<int>>& res)
    {
        if (curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            // skip if element exists already
            if (find(curr.begin(), curr.end(), nums[i]) != curr.end()) continue;
            
            curr.push_back(nums[i]);
            backtrack(nums, curr, res);
            curr.pop_back();
        }
    }
}; 