class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<int> last(26, -1);
        
        long long ans = 0;
        for(int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            dp[i+1] = dp[i] + 1 + (i - last[index] - 1);
            ans += dp[i+1];
            
            last[index] = i;
        }
        
        return ans;
    }
};