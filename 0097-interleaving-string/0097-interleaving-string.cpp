class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {        
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) return false;
        
        bool dp[m+1][n+1];
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = false;
        
        dp[m][n] = true;
        
        for (int i = m; i >= 0; i--) 
        {
            for (int j = n; j >= 0; j--)
            {
                if (i < m && s3[i + j] == s1[i] && dp[i+1][j])
                    dp[i][j] = true;
                if (j < n && s3[i + j] == s2[j] && dp[i][j+1])
                    dp[i][j] = true;
            }
        }
        
        return dp[0][0];
    }
};