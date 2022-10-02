class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int total = 0;
        
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '1')
                {
                    dfs(grid, r, c);
                    total++;
                }
            }
        }
        
        return total;
    }
    
    void bfs(vector<vector<char>>& grid, int row, int col)
    {
        int offset[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            grid[curr.first][curr.second] = '0';
            
            for (int k = 0; k < 4; k++)
            {
                int r = curr.first + offset[k][0];
                int c = curr.second + offset[k][1];
                
                if (valid(grid, r, c) && grid[r][c] == '1')
                    q.push({r, c});
            }
        }
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if (!valid(grid, r, c) || grid[r][c] == '0') return;
        
        if (grid[r][c] == '1') grid[r][c] = '0';
        
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
    
    bool valid(vector<vector<char>>& grid, int r, int c)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }
};