class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int left = 0, right = n-1;
        
        while (left < right)
        {
            for (int i = 0; i < right - left; i++)
            {
                int top = left, bottom = right,
                    topLeft = matrix[top][left + i];

                // top left
                matrix[top][left + i] = matrix[bottom - i][left];
                
                // bottom left
                matrix[bottom - i][left] = matrix[bottom][right - i];
                
                // bottom right
                matrix[bottom][right - i] = matrix[top + i][right];
                
                // top right
                matrix[top + i][right] = topLeft;
            }
                        
            left++;
            right--;
        }
    }
};