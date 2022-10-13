class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.length(), n = text2.length();
        int dp[m+1][n+1];
        
        for (int i = 0; i <= m; i++) dp[i][n] = 0;
        for (int i = 0; i <= n; i++) dp[m][i] = 0;
        
        for (int i = m-1; i >= 0; i--)
            for (int j = n-1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        
        return dp[0][0];
    }
};

//   a b c d e N
// a 1 1 1 1 1 0
// c 1 1 2 2 2 0
// e 1 1 2 2 3 0
// M 0 0 0 0 0 0

// pos[i][j] = max(pos[i-1][j], pos[i][j-1]) + charA == charB