class Solution {
public:
    
    vector<vector<char>> dict = {{'a', 'b', 'c'},
                                 {'d', 'e', 'f'},
                                 {'g', 'h', 'i'},
                                 {'j', 'k', 'l'},
                                 {'m', 'n', 'o'},
                                 {'p', 'q', 'r', 's'},
                                 {'t', 'u', 'v'},
                                 {'w', 'x', 'y', 'z'}};
    
    vector<string> letterCombinations(string digits) 
    {
        if (digits == "") return {};
        
        vector<string> res;
        backtrack(digits, res, "", 0);
        
        return res;
    }
    
    void backtrack(string digits, vector<string>& res, string curr, int i)
    {
        if (i >= digits.size())
        {
            res.push_back(curr);
            return;
        }
        
        int digit = digits[i] - '2';
        for (char ch : dict[digit])
        {
            curr.push_back(ch);
            backtrack(digits, res, curr, i+1);
            curr.pop_back();
        }
    }
};