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
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            int ans = 0;
            for(auto num: nums) {
                if(i - num >= 0) {
                    ans += dp[i - num];
                }
            }
            dp[i] = ans;
        }
        return dp[target];
    }
};