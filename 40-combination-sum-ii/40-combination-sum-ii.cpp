class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        
        combinationSum2(candidates, res, curr, target, 0);
        
        return res;
    }
    
    void combinationSum2(vector<int> candidates, vector<vector<int>>& res, vector<int> curr, int target, int start) 
    {
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++)
        {
            if ((target - candidates[i]) >= 0)
            {
                if (i > start && candidates[i] == candidates[i-1]) continue;
                curr.push_back(candidates[i]);
                combinationSum2(candidates, res, curr, target - candidates[i], i+1);
                curr.pop_back();
            }
        }
    }
};