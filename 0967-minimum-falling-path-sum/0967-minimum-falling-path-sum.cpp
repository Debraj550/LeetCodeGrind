class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(i == m-1) dp[i][j] = matrix[i][j];
                else {
                    int bottomLeft = j > 0 ? dp[i+1][j-1] : INT_MAX; 
                    int bottom = dp[i+1][j];
                    int bottomRight = j < n-1 ? dp[i+1][j+1]: INT_MAX;
                    dp[i][j] = matrix[i][j] + min({bottomLeft, bottom, bottomRight});
                }
            }
        }

        int res = INT_MAX;
        for(int i = 0; i < n; i++) {
            res = min(res, dp[0][i]);
        }
        return res;
    }
};