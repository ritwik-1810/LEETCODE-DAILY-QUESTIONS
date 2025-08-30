class Solution {
public:
    bool isValid(vector<vector<int>>&board)
    {
        return board[0][0]==1 && board[0][1]==2 && board[0][2]==3 &&
           board[1][0]==4 && board[1][1]==5 && board[1][2]==0;
    }
     string boardToString(vector<vector<int>>& board)
     {

        string tmp = "";

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
              tmp +=to_string(board[i][j]);
            }
        }

        return tmp;
    }

    unordered_map<string, int> memo;

    void solve(vector<vector<int>>&board,int i,int j,int &mini,int ans)
    {

        if(board[1][2]==0)
        {
            if(isValid(board))
              mini=min(ans,mini);
        }

         string converted = boardToString(board);
        if(memo.find(converted) != memo.end() && memo[converted] <= ans){ 
            return;
        }
        memo[converted] = ans;

        if(j-1>=0)
        {
            swap(board[i][j-1],board[i][j]);
            solve(board,i,j-1,mini,ans+1);
            swap(board[i][j-1],board[i][j]);
        }

        if(j+1<board[0].size())
        {
            swap(board[i][j+1],board[i][j]);
            solve(board,i,j+1,mini,ans+1);
            swap(board[i][j+1],board[i][j]);
        }

        if(i-1>=0)
        {
            swap(board[i-1][j],board[i][j]);
            solve(board,i-1,j,mini,ans+1);
            swap(board[i-1][j],board[i][j]);
        }

        if(i+1<board.size())
        {
            swap(board[i+1][j],board[i][j]);
            solve(board,i+1,j,mini,ans+1);
            swap(board[i+1][j],board[i][j]); 
        }

    }
    int slidingPuzzle(vector<vector<int>>& board) {
        pair<int,int>pt;

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]==0)
                {
                 pt.first=i;
                 pt.second=j;
                }
            }
        }

        if(board[0][0]==1 && board[0][1]==2 && board[0][2]==3 && board[1][0]==4 && board[1][1]==5)
        {
             return 0;
        }
        
        int mini=INT_MAX;
        solve(board,pt.first,pt.second,mini,0);
    
        if(mini==INT_MAX) return -1;

        return mini;
        
    }
};