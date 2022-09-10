class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> curr;
        vector<vector<int>> res;
        res.push_back(vector<int>());
        
        for (int i = 0; i < nums.size(); i++)
        {
            int n = res.size();

            for (int j = 0; j < n; j++)
            {
                curr = res[j];
                curr.push_back(nums[i]);
                
                res.push_back(curr);
            }
        }
                
        return res;
    }
};