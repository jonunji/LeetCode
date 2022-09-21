class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            int low = 0, high = matrix[i].size() - 1;
            
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                
                if (matrix[i][mid] < target)
                    low = mid + 1;
                
                else if (matrix[i][mid] > target)
                    high = mid - 1;
                
                else
                    return true;
            }
        }
        
        return false;
    }
};