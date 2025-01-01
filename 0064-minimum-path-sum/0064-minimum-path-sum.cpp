class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1, 0}};

    int solve(vector<vector<int>> &grid, int m, int n, int r, int c,vector<vector<int>> &dp) {
        if(r < 0 || c < 0 || r >=m || c >= n) return INT_MAX;
        if(r == m-1 && c == n-1) return grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        int mini = INT_MAX;
        for(auto dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(solve(grid, m, n, nr, nc, dp) != INT_MAX)
                mini = min(grid[r][c] + solve(grid, m, n, nr, nc, dp), mini);
        }
        return dp[r][c] = mini;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = solve(grid, m, n, 0, 0, dp);
        return res == INT_MAX ? -1 : res;
    }
};