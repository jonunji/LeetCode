class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        set<char> nums; 
        
        // checks the rows
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                if (isdigit(board[i][j]))
                    if (!nums.insert(board[i][j]).second)
                        return false;
            
            nums.clear();
        }
        
        // checks the columns
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                if (isdigit(board[j][i]))
                    if (!nums.insert(board[j][i]).second)
                        return false;
            
            nums.clear();
        }
        
        // checks the squares
        for(int p = 0; p < 9; p += 3)
            for (int i = 0; i < 9; i += 3)
            {
                for (int j = 0; j < 3; j++)
                    for (int k = 0; k < 3; k++)
                        if (isdigit(board[j+i][k+p]))
                            if (!nums.insert(board[j+i][k+p]).second)
                                return false;

                nums.clear();
            }
        
        return true;
    }
};