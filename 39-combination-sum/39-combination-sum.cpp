class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> attempt;
        comboSumHelper(candidates, res, target, attempt, 0);
        
        return res;
    }
    
    void comboSumHelper(vector<int>& candidates, vector<vector<int>>& res, int target, vector<int> attempt, int i)
    {
        if (target == 0)
        {
            res.push_back(attempt);
            return;
        }
        
        for (; i < candidates.size() && target >= candidates[i]; i++)
        {
            attempt.push_back(candidates[i]);
            comboSumHelper(candidates, res, target - candidates[i], attempt, i);
            attempt.pop_back();
        }
    }
};