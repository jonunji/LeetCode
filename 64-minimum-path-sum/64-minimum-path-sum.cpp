class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int matrix[grid.size()][grid[0].size()];
        
        matrix[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) 
            matrix[i][0] = matrix[i-1][0] + grid[i][0];
        for (int i = 1; i < grid[0].size(); i++) 
            matrix[0][i] = matrix[0][i-1] + grid[0][i];
        
        for (int i = 1; i < grid.size(); i++)
            for (int j = 1; j < grid[0].size(); j++)
                matrix[i][j] = grid[i][j] + min(matrix[i-1][j], matrix[i][j-1]);
        
        return matrix[grid.size() - 1][grid[0].size() - 1];
    }
};