class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++)     dfs(board, i, 0), dfs(board, i, n - 1);
        for (int i = 1; i < n-1; i++)   dfs(board, 0, i), dfs(board, m - 1, i);
        
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int r, int c)
    {
        if (!valid(board, r, c) || board[r][c] != 'O') return;
        
        board[r][c] = '#';
        
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
    
    bool valid(vector<vector<char>>& board, int r, int c)
    {
        int rows = board.size();
        int cols = board[0].size();
        
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }
};