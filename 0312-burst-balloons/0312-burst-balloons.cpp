class Solution {
private:
    vector<vector<int>> dp;
    
    int solve(vector<int> &nums, int left, int right) {
        if(left > right) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        
        int res = 0;
        for(int i = left; i <= right; i++) {
            int points = nums[i] * nums[left-1] * nums[right+1];
            int remaining = solve(nums, left, i-1) + solve(nums, i+1, right);
            res = max(res, points + remaining);
        }
        dp[left][right] = res;
        return res;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        dp.resize(n, vector<int>(n,-1));
        
        return solve(nums, 1, n-2);
    }
};