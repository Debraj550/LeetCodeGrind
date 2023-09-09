class Solution {
public:
    int solve(vector<int> &nums, int target, vector<int> &dp) {
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(auto num: nums) {
            if(target - num >= 0) {
                ans += solve(nums, target - num, dp);
            }
        }
        return dp[target] = ans;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, target, dp);
    }
};