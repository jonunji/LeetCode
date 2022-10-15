class Solution {
public:
    int change(int n, vector<int>& coins) 
    {
        int m = coins.size();
        int dp[m][n+1];
        
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) 
        {
            int c = i - coins[0];

            dp[0][i] = c < 0 ? 0 : dp[0][c];
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int c = j - coins[i];
                c = c < 0 ? 0 : dp[i][c];
                
                dp[i][j] = c + dp[i-1][j];
            }
        }
        
        return dp[m-1][n];   
    }
};


//   0 1 2 3 4 5
// 1 1 1 1 1 1 1  
// 2 1 1 2 2 3 3
// 5 1 1 2 2 3 4
      
      

