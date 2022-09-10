class Solution {
public:
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        helper(res, "", 0, 0, n);
        return res;
    }
    
    void helper(vector<string> &res, string curr, int lpc, int rpc, int n)
    {
        if (rpc == n && lpc == n)
            res.push_back(curr);
        
        if (lpc < n)
            helper(res, curr + "(", lpc + 1, rpc, n);
        if (rpc < n && lpc > rpc)
            helper(res, curr + ")", lpc, rpc + 1, n);
    }
};