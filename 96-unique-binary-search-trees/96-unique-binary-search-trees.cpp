class Solution {
public:
    int numTrees(int n) 
    {
        //                n = 0  1
        vector<int> result = {1, 1};
        int  i, j;
        
        for (i = 2; i <= n; i++)
        {
            result.push_back(0);
            
            for (j = 1; j <= i; j++)
                result[i] += result[i - j] * result[j - 1];
        }
        
        return result[n];
    }
};