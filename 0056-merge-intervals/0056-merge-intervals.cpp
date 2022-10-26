class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        vector<int> pair = intervals[0];
        
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] > pair[1])
            {
                res.push_back(pair);
                pair = intervals[i];
            }
            else
                pair = {min(pair[0], intervals[i][0]), 
                        max(pair[1], intervals[i][1])};
        }
        
        res.push_back(pair);            
        return res;
    }
};


