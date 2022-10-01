class Solution {
public:
    //                       up     down    left    right
    int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        const int m = board.size();
        const int n = board[0].size();
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (backtrack(board, word, i, j, 0))
                    return true;
                
        return false;
    }
    
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int strIndex)
    {
        if (strIndex == word.size()) 
            return true;
        
        if (!valid(board.size(), board[0].size(), i, j) || board[i][j] != word[strIndex]) 
            return false;
        // cout << word[strIndex] << "  " << board[i][j] << endl;
        
        char c = board[i][j];
        board[i][j] = '*';
        
        for (int k = 0; k < 4; k++)
        {
            int x = i + directions[k][0];
            int y = j + directions[k][1];
            
            if (backtrack(board, word, x, y, strIndex+1)) return true;
        }
        
        board[i][j] = c;
        
        return false;
    }
    
    bool valid(int m, int n, int i, int j)
    {
        return i < m && i >= 0 && j < n && j >= 0;
    }
};