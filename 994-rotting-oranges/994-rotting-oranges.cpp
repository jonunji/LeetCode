class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int time = -1;
        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int offset[5] = {0, 1, 0, -1, 0};
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2) // rotten
                    q.push({i, j});
                
                else if (grid[i][j] == 1) // fresh
                    fresh++;
            }
                
        
        while (!q.empty())
        {
            time++;
            
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                
                for (int k = 0; k < 4; k++)
                {
                    int r = row + offset[k];
                    int c = col + offset[k+1];
                    
                    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) continue;
                    
                    grid[r][c] = 2;
                    q.push({r, c});
                    fresh--;
                }
                
                q.pop();
            }
        }
        
        return fresh ? -1 : max(0, time);
    }
};