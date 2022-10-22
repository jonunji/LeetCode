class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n = s.length();
        int last[26] = {-1};
        
        vector<int> res;
        
        for (int i = n-1; i >= 0; i--) 
            last[s[i] - 'a'] = max(i, last[s[i] - 'a']);
        
        int start = 0, maxPos = 0;
        for (int i = 0; i < n; i++)
        {
            int c = last[s[i] - 'a'];
                         
            maxPos = max(maxPos, c);
            if (i == maxPos)
            {
                res.push_back(i - start + 1);
                start = i+1;
            }
        }    
        
        return res;
    }
};