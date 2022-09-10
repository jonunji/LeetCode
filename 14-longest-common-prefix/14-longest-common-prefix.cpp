class Solution {
public:        
    string longestCommonPrefix(vector<string>& strs) 
    {
        // start index at same spot, go until either no match
        // between any, or string out of characters
        int i, j;
        string str;
        
        str = strs[0]; 
        
        for (i = 1; i < strs.size(); i++)
            for (j = str.length() - 1; j >= 0; j--)
                if (strs[i][j] != str[j])
                    str = str.substr(0, j);

        return str;
    }
};