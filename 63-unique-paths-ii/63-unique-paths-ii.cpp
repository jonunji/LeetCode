class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        if (grid[0][0] == 1)
            return 0;
        
        int matrix[grid.size()][grid[0].size()];
        
        matrix[0][0] = 1;
        
        for (int i = 1; i < grid.size(); i++) 
            matrix[i][0] = (grid[i][0] == 1) ? 0 : matrix[i-1][0];   
        for (int i = 1; i < grid[0].size(); i++) 
            matrix[0][i] = (grid[0][i] == 1) ? 0 : matrix[0][i-1];   
        
        for (int i = 1; i < grid.size(); i++)
            for (int j = 1; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    matrix[i][j] = 0;
                else 
                    matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        
        return matrix[grid.size()-1][grid[0].size()-1];
    }
};