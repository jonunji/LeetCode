class Solution {
public:
    
    int numDecodings(string s) 
    {
        int dp1 = 1, dp2, n = s.length();
        
        for (int i = n-1; i >= 0; i--)
        {
            int curr = s[i] == '0' ? 0 : dp1;
            
            if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) 
                curr += dp2;
            
            dp2 = dp1;
            dp1 = curr;
        }
        
        return dp1;
    }
};