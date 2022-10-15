class Solution {
public:
    int change(int n, vector<int>& coins) 
    {
        int m = coins.size();
        int dp[m][n+1];
        
        // first column, 1 way to make amount of 0
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int c = j - coins[i];
                dp[i][j] = c < 0 ? 0 : dp[i][c];
                
                if (i > 0) dp[i][j] += dp[i-1][j];
            }
            cout << endl;
        }
        
        return dp[m-1][n];   
    }
};


//   0 1 2 3 4 5
// 1 1 1 1 1 1 1  
// 2 1 1 2 2 3 3
// 5 1 1 2 2 3 4
      
      

