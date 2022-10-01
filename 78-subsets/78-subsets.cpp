class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> curr;
        backtrack(nums, 0, curr);
        
        return res;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int> curr)
    {
        res.push_back(curr);

        for (int i = start; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            backtrack(nums, i+1, curr);
            curr.pop_back();
        }
    }
};