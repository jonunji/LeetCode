class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        set<char> nums;
        
        // check the columns
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                if (isdigit(board[i][j]) && !nums.insert(board[i][j]).second)
                    return false;
            
            nums.clear();
        }
        
        
        // check the rows
        nums.clear();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                if (isdigit(board[j][i]) && !nums.insert(board[j][i]).second)
                    return false;
            
            nums.clear();
        }
        
        // check the boxes
        nums.clear();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int row = (i / 3 * 3) + (j / 3);
                int col = (j % 3) + (i % 3 * 3);
                
                if (isdigit(board[row][col]) && !nums.insert(board[row][col]).second)
                    return false;
            }

            nums.clear();
        }
        
        return true;
    }
};