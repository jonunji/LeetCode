class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int col[9][9] = {0};
        int row[9][9] = {0};
        int box[3][3][9] = {0};
        
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    if (row[i][num]++) return false;
                    if (col[j][num]++) return false;
                    if (box[i/3][j/3][num]++) return false;
                }
        
        return true;
    }
};