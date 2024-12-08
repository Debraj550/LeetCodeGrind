class Solution {
public:
    int upperBound(vector<vector<int>>& events, int idx){
        int l = idx + 1, h = events.size() - 1, nextIndex = events.size();
        while (l <= h) {
            int mid = (l+h)/2;
            if (events[mid][0] > events[idx][1]){
                nextIndex = mid;
                h = mid - 1;
            }else{
               l = mid + 1; 
            }
        }
        return nextIndex;
    }
    int solve(vector<vector<int>> &events, int idx, int jobs, vector<vector<int>> &dp) {
        if(jobs == 2 || idx == events.size()) return 0;
        if(dp[idx][jobs] != -1) return dp[idx][jobs];
        int nextindex = upperBound(events, idx);
        int include = events[idx][2] + solve(events, nextindex, jobs + 1, dp);
        int notInclude = solve(events, idx + 1, jobs, dp);
        return dp[idx][jobs] = max(include, notInclude);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(events, 0, 0, dp);
    }
};


