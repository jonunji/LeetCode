class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> curr;
        
        permute(nums, res, curr);
        
        return res;
    }
    
    void permute(vector<int> nums, vector<vector<int>>& res, vector<int> curr) 
    {
        if (nums.empty())
            res.push_back(curr);
        
        vector<int> tempNums = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            swap(tempNums[nums.size() - 1], tempNums[i]);
            tempNums.pop_back();
            curr.push_back(nums[i]);
            
            permute(tempNums, res, curr);
            
            tempNums.push_back(nums[i]);
            swap(tempNums[nums.size() - 1], tempNums[i]);
            curr.pop_back();
        }
    }
};