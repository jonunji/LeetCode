class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        int res = 0;
        
        sort(intervals.begin(), intervals.end());
        vector<int> cur = intervals[0];
        
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= cur[1])
                cur = intervals[i];
            else
            {
                if (intervals[i][1] < cur[1])
                    cur = intervals[i];
                
                res++;
            }
        }

        return res;
    }
};