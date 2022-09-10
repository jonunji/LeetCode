class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, i = 0, j = 0;
        
        vector<vector<int>> arr(n, vector<int>(n, -1));
        arr[0][0] = 1;
        
        while (arr[i][j] != n * n)
        {
            int temp = arr[i][j];
            int x = i + dir[d%4][0], y = j + dir[d%4][1];
            
            if (x < 0 || x >= n || y < 0 || y >= n || arr[x][y] != -1)
            {
                d++;
                i += dir[d%4][0];
                j += dir[d%4][1];  
            }
            else
            {
                i = x;
                j = y;  
            }
            
            arr[i][j] = temp + 1;
        }
        
        return arr;
    }
};