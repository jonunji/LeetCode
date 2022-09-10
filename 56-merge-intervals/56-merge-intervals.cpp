class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& vec) 
    {
        vector<vector<int>> res;
        int j = vec.size() - 2;
        
        sort(vec.begin(), vec.end(), [](const std::vector<int>& a, const std::vector<int>& b) 
             {
                return a[0] < b[0];
             });
        
        reverse(vec.begin(), vec.end());
        
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            
            for (; j >= 0; j--)
            {
                if (vec[i][1] < vec[j][0]) break;
                
                vec[j] = { min(vec[i][0], vec[j][0]),
                           max(vec[i][1], vec[j][1])};
                
                i = j;
            }
            
            res.push_back(vec[j+1]);
        }
        
        return res;
    }
};