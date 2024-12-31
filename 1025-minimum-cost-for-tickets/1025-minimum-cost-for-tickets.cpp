class Solution {
public:
    unordered_map<string, int> dp;
    int solve(vector<int> &days, vector<int> &costs, int dayIdx, int travelledTill) {
        if(dayIdx >= days.size()) return 0;
        string cacheKey = to_string(dayIdx)+"-"+to_string(travelledTill);
        if(dp.find(cacheKey) != dp.end()) return dp[cacheKey];
        if(travelledTill > days[dayIdx]) return solve(days, costs, dayIdx + 1, travelledTill);

        int oneDayPassCost = costs[0] + solve(days, costs, dayIdx + 1, days[dayIdx] + 1);
        int sevenDayPassCost = costs[1] + solve(days, costs, dayIdx + 1, days[dayIdx] + 7);
        int ThirtyDayPassCost = costs[2] + solve(days, costs, dayIdx + 1, days[dayIdx] + 30);

        return dp[cacheKey] = min({oneDayPassCost,sevenDayPassCost, ThirtyDayPassCost});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        ans = solve(days, costs, 0, 0);
        return ans;
    }
};

