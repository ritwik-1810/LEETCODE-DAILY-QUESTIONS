class Solution {
public:
    int m, n, K;
    vector<unordered_map<int,int>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int rem) {
        if(i >= m || j >= n) return 0;

        int newRem = (rem + grid[i][j]) % K;

        if(i == m-1 && j == n-1)
            return newRem == 0;

        int pos = i * n + j;

        if(dp[pos].count(rem)) return dp[pos][rem];

        long long ways = 0;

        ways += solve(grid, i+1, j, newRem);
        ways += solve(grid, i, j+1, newRem);

        return dp[pos][rem] = ways % 1000000007;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        K = k;

        dp.resize(m * n);

        return solve(grid, 0, 0, 0);
    }
};
