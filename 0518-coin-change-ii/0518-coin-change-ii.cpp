class Solution {
public:
     vector<vector<int>> dp;
    int solve(int i, int sum, int amount, vector<int> &coins) {
    if(sum == amount) return 1;
    if(sum > amount || i == coins.size()) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    
    int take = solve(i, sum + coins[i], amount, coins);
    int notTake = solve(i+1, sum, amount, coins);
    
    return dp[i][sum] =take + notTake;
}
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size() + 1, vector<int>(amount + 1, -1)); // fix size
        int res = 0;
        res = solve(0, 0, amount, coins);
        return res;
    }
};
