class Solution {
public:
    vector<vector<int>> dirs{{-1, 1}, {0, 1}, {1, 1}};

    int traverse(vector<vector<int>>& grid, int m, int n, int row, int col, int prevVal, vector<vector<int>> &dp) {
        if(row >= m || row < 0 || col >= n || col < 0) return 0;
        if(prevVal != -1 && grid[row][col] <= prevVal) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int moves = 0;
        for(auto dir: dirs) {
            int nRow = row + dir[0];
            int nCol = col + dir[1];
            moves = max(moves, 1 + traverse(grid, m, n, nRow, nCol, grid[row][col], dp));
        }
        dp[row][col] = moves;
        return moves;

    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int moves = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++) {
            int currVal = grid[i][0];
            int prevVal = -1;
            moves = max(moves, traverse(grid, m, n, i, 0, -1, dp));
        }
        return moves -1;
    }
};