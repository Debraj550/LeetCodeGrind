class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int end, int zero, int one, int &ans, vector<int> &dp) {
        if(end == 0) return 1;
        if(dp[end] != -1) return dp[end];
        int count = 0;
        if(end >= zero) count += solve(end - zero, zero, one, ans, dp)%mod;
        if(end >= one) count += solve(end - one, zero, one, ans, dp)%mod;
        return dp[end] = count;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<int> dp(high+1, -1);
        for(int i = low; i <= high; i++) {
            ans = ans %mod + solve(i, zero, one, ans, dp) % mod;
        }
        return ans % mod;
    }
};