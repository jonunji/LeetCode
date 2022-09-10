class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> curr;
        
        backtrack(n, k, 1, res, curr);
        
        return res;
    }
    
    void backtrack(int n, int k, int start, vector<vector<int>>& res, vector<int> curr)
    {
        if (k == 0)
        {
            res.push_back(curr);
            
            return;
        }
        
        for (int i = start; i <= n; i++)
        {
            curr.push_back(i);
            
            backtrack(n, k-1, i+1, res, curr);
            
            curr.pop_back();
        }
    }
};