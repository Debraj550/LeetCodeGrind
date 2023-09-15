class Solution {
private:
    vector<vector<int>> dp;
    int bisectRight(vector<vector<int>> &events, int target) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }   
    
    int solve(vector<vector<int>> &events, int idx, int n, int k) {
        if(idx == n || k == 0) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        int nextIndex = bisectRight(events, events[idx][1]);
        
        int take = 0, notTake = 0;
        take = events[idx][2] + solve(events, nextIndex, n, k - 1);
        notTake = solve(events, idx + 1, n, k);
        
        return dp[idx][k] = max(take, notTake);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        dp.resize(events.size(), vector<int>(k+1, -1));
        return solve(events, 0, events.size(), k);;
    }
};