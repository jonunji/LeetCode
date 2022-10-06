class Solution {
public:
    
    int count = 0;
    
    int countSubstrings(string s) 
    {
        int len = s.length();
        if (len < 2) return len;
        
        for (int i = 0; i < len; i++)
        {
            expand(s, i, i);
            expand(s, i, i+1);
        }
        
        return count;
    }
    
    void expand(string s, int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r])
            count++, l--, r++;
    }
};