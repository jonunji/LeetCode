class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> curr;
        set<int> exists;
        backtrack(nums, curr, res, exists);
        
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int> curr, vector<vector<int>>& res, set<int> exists)
    {
        if (curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            // skip if element exists already
            if (exists.find(nums[i]) != exists.end()) continue;
            
            curr.push_back(nums[i]);
            exists.insert(nums[i]);
            
            backtrack(nums, curr, res, exists);
             
            exists.erase(nums[i]);
            curr.pop_back();
        }
    }
}; 