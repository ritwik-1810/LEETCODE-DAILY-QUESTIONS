class Solution {
public:
    int row;
    int col;
    int s;

    int MOD = 1e9+7;

    vector<vector<vector<int>>> dp;  // FIX #1: dynamic DP

    int solve(vector<vector<int>>& grid ,int i,int j,int row,int col,int rem,int k)
    {
         if(i>=row || j>=col)
           return INT_MAX;

         if(i==row-1 && j==col-1)
         {
              if((grid[i][j]+rem)%k == 0) return 1;

              return INT_MAX;
         }

         // FIX #2: correct index -> rem, not k
         if(dp[i][j][rem] != -1) 
             return dp[i][j][rem];

         int ans = 0;

         int newRem = (grid[i][j] + rem) % k;

         int down = solve(grid, i+1, j, row, col, newRem, k);

         if(down != INT_MAX)
             ans = (ans + down) % MOD;

         int right = solve(grid, i, j+1, row, col, newRem, k);

         if(right != INT_MAX)
             ans = (ans + right) % MOD;

         return dp[i][j][rem] = ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        row = grid.size();
        col = grid[0].size();
        // FIX #3: dynamic DP allocation instead of illegal static size
        dp.assign(row, vector<vector<int>>(col, vector<int>(k, -1)));

        int ans = solve(grid, 0, 0, row, col, 0, k);

        if(ans == INT_MAX) return 0;

        return ans;
    }
};
