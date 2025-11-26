class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int r1, int c1, int r2) {

        int c2 = r1 + c1 - r2;

        // Out of bounds or thorn
        if (r1 >= m || c1 >= n || r2 >= m || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;  // big negative to avoid overflow

        // Reached end
        if (r1 == m - 1 && c1 == n - 1)
            return grid[r1][c1];

        // Memo hit
        if (dp[r1][c1][r2] != -1e9)
            return dp[r1][c1][r2];

        // Cherry count
        int cherries = (r1 == r2 && c1 == c2)
                        ? grid[r1][c1]
                        : grid[r1][c1] + grid[r2][c2];

        // Transitions
        int best = max({
            solve(grid, r1+1, c1,   r2+1),
            solve(grid, r1,   c1+1, r2),
            solve(grid, r1+1, c1,   r2),
            solve(grid, r1,   c1+1, r2+1)
        });

        return dp[r1][c1][r2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(m, -1e9)));

        int ans = solve(grid, 0, 0, 0);
        return max(0, ans);
    }
};
