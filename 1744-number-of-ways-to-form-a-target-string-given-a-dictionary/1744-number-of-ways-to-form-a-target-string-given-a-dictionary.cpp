class Solution {
public:
    int MOD = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].size();
        int t = target.size();

        vector<vector<int>> freq(26, vector<int>(m, 0));
        for (const string& word : words) {
            for (int j = 0; j < m; j++) {
                freq[word[j] - 'a'][j]++;
            }
        }

        vector<vector<int>> dp(t + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j - 1];
                char targetChar = target[i - 1];
                int charIndex = targetChar - 'a';
                dp[i][j] = (dp[i][j] + (long long)freq[charIndex][j - 1] * dp[i - 1][j - 1] % MOD) % MOD;
            }
        }

        return dp[t][m];
    }
};
