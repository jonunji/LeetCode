class Solution {
public:
    int minimumTotal(vector<vector<int>>& t)
    {
        int i, row; 
        
        if (t.size() == 1)
            return t[0][0];
        
        // row size <= is the same as determining t[row].size()
        for (row = (t.size() - 2); row >= 0; row--)
            for (i = 0; i <= row; i++)  
                t[row][i] += min(t[row+1][i], t[row+1][i+1]);
    
        return t[0][0];
    }
};