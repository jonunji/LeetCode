class Solution {
public:
//     DP solution
//     string longestPalindrome(string s) 
//     {
//         int n = s.size();
//         int left = 0, right = 0;
        
//         vector<vector<bool>> dp(n, vector<bool>(n));
//         for (int i = 0; i < n; i++) 
//         {
//             // sets up diagonal
//             dp[i][i] = true;
            
//             // sets up two letters
//             if (i < n-1) 
//             {
//                 dp[i][i+1] = s[i] == s[i+1];
                
//                 if (dp[i][i+1]) 
//                     right = i+1, left = i;
//             }
//         }
        
//         for (int i = n-3; i >= 0; i--)
//             for (int j = i+2; j < n; j++)
//             {
//                 dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                
//                 if (dp[i][j] && j - i > right - left) 
//                     right = j, left = i;
//             }
        
//         return s.substr(left, right-left+1);
//     }
    
    int maxLen = 0, start = 0;
    
    string longestPalindrome(string s) 
    {
        int len = s.length();
        if (len < 2) return s;
        
        for (int i = 0; i < len-1; i++)
        {
            extendPalindrome(s, i, i);
            extendPalindrome(s, i, i+1);
        }
        
        return s.substr(start, maxLen);
    }
    
    void extendPalindrome(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right]) 
            left--, right++;
        
        if (right - left - 1 > maxLen) 
        {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};