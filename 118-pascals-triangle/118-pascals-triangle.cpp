class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res;
        vector<int> curr(numRows, 1);
        
        res.push_back(vector<int>(curr.begin(), curr.begin() + 1));
        
        if (numRows >= 2)
            res.push_back(vector<int>(curr.begin(), curr.begin() + 2));
        
        for (int j = 2; j < numRows; j++)
        {
            for (int i = 1; i < j; i++)
            {
                curr[i] = (res[j-1][i-1] + res[j-1][i]);
            }
            
            res.push_back(vector<int>(curr.begin(), curr.begin() + j + 1));                
        }
        
        return res;
    }
};