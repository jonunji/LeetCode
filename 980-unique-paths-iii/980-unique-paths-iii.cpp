class Solution {
public:
    
    vector<int> analyzeGrid(vector<vector<int>>& grid)
    {
        vector<int> res(3, 0);
        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                    res[2]++;
                else if (grid[i][j] == 1)        
                {
                    res[0] = i;
                    res[1] = j;
                }
            }
        
        return res;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int totalPaths = 0;
        vector<int> gridData = analyzeGrid(grid);
        
        uniquePaths(grid, totalPaths, 0, gridData[2], gridData[0], gridData[1]);
        
        return totalPaths;
    }
    
    void uniquePaths(vector<vector<int>> grid, int& totalPaths, int currCount, int totalCount, int i, int j)
    {
        if (currCount == totalCount+1 && grid[i][j] == 2)
        {
            totalPaths++;
            return;
        }
        
        int prevVal = grid[i][j];
        grid[i][j] = -1;

        // up
        if (i-1 >= 0 && grid[i-1][j] != -1)
            uniquePaths(grid, totalPaths, currCount + 1, totalCount, i-1, j);
        
        // down
        if (i+1 < grid.size() && grid[i+1][j] != -1)
            uniquePaths(grid, totalPaths, currCount + 1, totalCount, i+1, j);
        
        // right
        if (j+1 < grid[0].size() && grid[i][j+1] != -1)
            uniquePaths(grid, totalPaths, currCount + 1, totalCount, i, j+1);
        
        // left
        if (j-1 >= 0 && grid[i][j-1] != -1)
            uniquePaths(grid, totalPaths, currCount + 1, totalCount, i, j-1);
            
        grid[i][j] = prevVal;
    }
};