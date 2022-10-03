class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {        
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0; 
        
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                maxArea = max(dfs(grid, r, c), maxArea);
                
        return maxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (!valid(grid, r, c) || grid[r][c] == 0) return 0;
        
        int total = 1; // got here means grid[r][c] == 1
        grid[r][c] = 0;
        
        total += dfs(grid, r+1, c);
        total += dfs(grid, r-1, c);
        total += dfs(grid, r, c+1);
        total += dfs(grid, r, c-1);
        
        return total;
    }
    
    bool valid(vector<vector<int>>& grid, int r, int c)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }
};