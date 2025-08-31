class Solution {
public:
     bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;  // row check
            if (board[i][col] == c) return false;  // col check
            if (board[(row/3)*3 + i/3][(col/3)*3 + i%3] == c) return false; // box check
        }
        return true;
    }
    bool solve(vector<vector<char>>&board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(isValid(board,i,j,k))
                        {
                         board[i][j]=k;

                         if(solve(board)) return true;

                         board[i][j]='.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         
         int row=board.size();

         int col=board[0].size();

         solve(board);

         return;
    }
};