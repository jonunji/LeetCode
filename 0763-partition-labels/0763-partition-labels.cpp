class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n = s.length();
        int last[26] = {-1};
        
        vector<int> res;
        
        for (int i = n-1; i >= 0; i--)
        {
            int letter = s[i] - 'a';
            last[letter] = max(i, last[letter]);
        }
        
        
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            int c = last[s[i] - 'a'];
                         
            end = max(end, c);
            if (i == end)
            {
                res.push_back(i - start + 1);
                start = i+1;
            }
        }    
        
        return res;
    }
};