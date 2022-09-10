class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int i = s.length() - 1;
        int start = 0;
        
        while (i >= 0 && s[i] == ' ')
            i--;
        
        start = i;
        while (i >= 0 && s[i] != ' ')
            i--;
        
        return start - i;
    }
};