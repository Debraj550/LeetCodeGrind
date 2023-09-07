class Solution {
private:
    vector<vector<int>> dp;
    int solve(int idx, int remain, vector<int> &cost, vector<int> &time) {
        if(remain <= 0) return 0;
        if(idx >= cost.size()) return 1e9;
        if(dp[idx][remain] != -1) return dp[idx][remain];
        int paint = cost[idx] + solve(idx+1, remain - 1 - time[idx], cost, time);
        int dontPaint = solve(idx + 1, remain, cost, time);
        return  dp[idx][remain] = min(paint, dontPaint);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(0, n, cost, time);
    }
    
    
};