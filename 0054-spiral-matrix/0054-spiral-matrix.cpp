class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        
        int direction = 0,
            left = 0, 
            right = matrix[0].size() - 1, 
            top = 0, 
            bottom = matrix.size() - 1;
        
        while (left <= right && top <= bottom)
        {
            switch (direction)
            {
                // left to right
                case 0:
                    for (int i = left; i <= right; i++)
                        res.push_back(matrix[top][i]);
                    
                    top++;
                    break;
                
                // top to bottom
                case 1:
                    for (int i = top; i <= bottom; i++)
                        res.push_back(matrix[i][right]);
                    
                    right--;
                    break;
                  
                // right to left
                case 2:
                    for (int i = right; i >= left; i--)
                        res.push_back(matrix[bottom][i]);
                    
                    bottom--;
                    break;
                
                // bottom to top
                case 3:
                    for (int i = bottom; i >= top; i--)
                        res.push_back(matrix[i][left]);
                    
                    left++;
                    break;
            }
            
            direction = (direction + 1) % 4;
        }
        
        return res;
    }
};