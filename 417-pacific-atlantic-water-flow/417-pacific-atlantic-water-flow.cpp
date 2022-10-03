class Solution {
public:
    
    vector<vector<bool>> pacific, atlantic;
    vector<vector<int>> res;
        
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int rows = heights.size();
        int cols = heights[0].size();
        
        pacific = atlantic = vector<vector<bool>>(rows, vector<bool>(cols, false));
        
        for (int r = 0; r < rows; r++) { bfs(heights, pacific, r, 0); bfs(heights, atlantic, r, cols - 1); }
        for (int c = 0; c < cols; c++) { bfs(heights, pacific, 0, c); bfs(heights, atlantic, rows - 1, c); }
        
        return res;
    }
    
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col)
    {
        int offset[5] = {0, 1, 0, -1, 0};
        
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while (!q.empty())
        {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            if (pacific[row][col] && atlantic[row][col]) 
                res.push_back({row, col});
            
            for (int k = 0; k < 4; k++)
            {
                int r = row + offset[k];
                int c = col + offset[k+1];
                
                if (valid(grid, r, c) && grid[r][c] >= grid[row][col])
                    q.push({r, c});
            }
        }
    }
    
    bool valid(vector<vector<int>>& grid, int r, int c)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }
};