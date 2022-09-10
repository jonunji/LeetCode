class Solution {
public:    
    int lengthOfLongestSubstring(string s) 
    {
        set<char> str;
        int i = 0, j = 0, c = 0, n = s.length();
        
        while (i < n)
            if (str.count(s[i]) == 0)
            {                
                str.insert(s[i]);
                c = max(c, (int)str.size());
                i++;
            }
            else
            {               
                str.erase(s[j]);
                j++;
            }
        
        return c;
    }
};