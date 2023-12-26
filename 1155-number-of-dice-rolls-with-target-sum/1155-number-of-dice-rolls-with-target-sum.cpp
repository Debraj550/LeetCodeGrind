class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, 0));
        memo[n][target] = 1;
        
        for (int diceIndex = n - 1; diceIndex >= 0; diceIndex--) {
            for (int currSum = 0; currSum <= target; currSum++) {
                int ways = 0;
                for (int i = 1; i <= min(k, target - currSum); i++) {
                    ways = (ways + memo[diceIndex + 1][currSum + i]) % MOD;
                }
                
                memo[diceIndex][currSum] = ways;
            }
        }
        
        return memo[0][0];
    }
};