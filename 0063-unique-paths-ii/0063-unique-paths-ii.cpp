class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i == m-1 && j == n-1 && grid[i][j] != 1) return 1;
        if(i == m || j == n || grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans = solve(i + 1, j, m, n, grid, dp) + solve(i, j +1 , m , n, grid, dp);
        return dp[i][j] = ans;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, obstacleGrid, dp);
    }
};
