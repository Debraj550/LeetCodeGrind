class Solution {
public:
    int solve(int idx, int end, vector<int>& nums, vector<int>& dp) {
        if (idx > end) return 0;
        if (dp[idx] != -1) return dp[idx];
        int robCurrentHouse = nums[idx] + solve(idx + 2, end, nums, dp);
        int skipCurrentHouse = solve(idx + 1, end, nums, dp);
        return dp[idx] = max(robCurrentHouse, skipCurrentHouse);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp1(n, -1); 
        vector<int> dp2(n, -1); 
        int excludeLast = solve(0, n - 2, nums, dp1);
        int excludeFirst = solve(1, n - 1, nums, dp2);
        return max(excludeLast, excludeFirst);
    }
};
