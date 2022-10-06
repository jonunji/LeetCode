class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        int left = 0, right = 0;
        
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) 
        {
            // sets up diagonal
            dp[i][i] = true;
            
            // sets up two letters
            if (i < n-1) 
            {
                dp[i][i+1] = s[i] == s[i+1];
                
                if (dp[i][i+1]) 
                    right = i+1, left = i;
            }
        }
        
        for (int i = n-3; i >= 0; i--)
            for (int j = i+2; j < n; j++)
            {
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                
                if (dp[i][j] && j - i > right - left) 
                    right = j, left = i;
            }
        
        return s.substr(left, right-left+1);
    }
};