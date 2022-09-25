class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string str;
            
        parentheses(res, str, n, n);
        
        return res;
    }
    
    void parentheses(vector<string>& res, string& str, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(str);
            return;
        }
        
        str.push_back('(');
        if (left > 0) parentheses(res, str, left - 1, right);
        
        str.pop_back();
        
        str.push_back(')');
        if (right > left) parentheses(res, str, left, right - 1);
        
        str.pop_back();
    }
};