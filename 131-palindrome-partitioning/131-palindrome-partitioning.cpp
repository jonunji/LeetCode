class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, curr, res);
            
        return res;
    }
    
    void backtrack(string s, int start, vector<string> curr, vector<vector<string>>& res)
    {
        if (start >= s.length())
        {
            res.push_back(curr);
            return;
        }
        
        string pal = "";
        
        for (int i = start; i < s.length(); i++)
        {
            pal += s[i];
            
            if (!isPalindrome(pal)) continue;
            
            curr.push_back(pal);
            backtrack(s, i+1, curr, res);
            curr.pop_back();
        }
    }
    
    bool isPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;
        
        while (left <= right)
        {
            if (s[left] != s[right]) return false;
            
            left++;
            right--;
        }
        
        return true;
    }
};