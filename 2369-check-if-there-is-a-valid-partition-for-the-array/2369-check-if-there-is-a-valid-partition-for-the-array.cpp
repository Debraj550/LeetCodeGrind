class Solution {
public:
    vector<int> dp;
    bool solve(vector<int> &nums, int idx, int n) {
        if(idx > n) return true;
        if(dp[idx] != -1) return dp[idx];
        
        bool ans = false;
        if(idx < n && nums[idx] == nums[idx + 1]) {
            ans = ans | solve(nums, idx + 2, n);
        }
        if(idx < n - 1 && nums[idx] == nums[idx + 1] && nums[idx+1] == nums[idx+2]) {
            ans = ans | solve(nums, idx + 3, n);
        }
        if(idx < n - 1 && nums[idx] + 1== nums[idx + 1]  && nums[idx+1] + 1== nums[idx+2]) {
            ans = ans | solve(nums, idx + 3, n);
        }
        return dp[idx] = ans;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return solve(nums, 0, n-1);
    }
};