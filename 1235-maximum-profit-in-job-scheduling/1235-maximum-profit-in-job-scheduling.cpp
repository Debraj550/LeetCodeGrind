class Solution {
    
private:
    int solve(int currIdx, vector<vector<int>> &jobs, vector<int> &startTime, int n, vector<int> &dp) {
        if(currIdx >= n)
            return 0;
        if(dp[currIdx] != -1) 
            return dp[currIdx];
        
        int newIdx = lower_bound(startTime.begin(), startTime.end(), jobs[currIdx][1]) - startTime.begin();
        int pick = jobs[currIdx][2] + solve(newIdx, jobs, startTime, n, dp);
        int notPick = solve(currIdx+1, jobs, startTime, n, dp);
        return dp[currIdx] = max(pick, notPick);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        vector<int> dp(n, -1);
        
        for(int i = 0; i <n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        return solve(0, jobs, startTime, n,dp);
    }
};
