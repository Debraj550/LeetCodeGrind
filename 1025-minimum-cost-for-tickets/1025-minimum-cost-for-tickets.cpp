class Solution {
public:
    int solve(vector<int> &days, vector<int> &costs, int dayIdx, int travelledTill, vector<vector<int>> &dp) {
        if(dayIdx >= days.size()) return 0;
        if(dp[dayIdx][travelledTill] != -1) return dp[dayIdx][travelledTill];
        if(travelledTill > days[dayIdx]) return solve(days, costs, dayIdx + 1, travelledTill, dp);

        int oneDayPassCost = costs[0] + solve(days, costs, dayIdx + 1, days[dayIdx] + 1, dp);
        int sevenDayPassCost = costs[1] + solve(days, costs, dayIdx + 1, days[dayIdx] + 7, dp);
        int ThirtyDayPassCost = costs[2] + solve(days, costs, dayIdx + 1, days[dayIdx] + 30, dp);

        return dp[dayIdx][travelledTill] = min(oneDayPassCost, min(sevenDayPassCost, ThirtyDayPassCost));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        vector<vector<int>> dp(days.size(), vector<int>(1000, -1));
        ans = solve(days, costs, 0, 0, dp);
        return ans;
    }
};