class Solution {
public:
    int calSubsets(vector<int> &nums, int maxOr, int idx, int curr, vector<vector<int>> &dp) {
        
        if(idx == nums.size() ) return curr == maxOr;
        if(dp[idx][curr] != -1) return dp[idx][curr];
        
        int take = calSubsets(nums, maxOr, idx + 1, curr | nums[idx], dp);
        int notTake = calSubsets(nums, maxOr, idx + 1, curr, dp);
        return dp[idx][curr] = take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto num: nums) maxOr = maxOr | num;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(maxOr + 1, -1));
        int res = calSubsets(nums, maxOr, 0, 0, dp);
        return res;
    }
};