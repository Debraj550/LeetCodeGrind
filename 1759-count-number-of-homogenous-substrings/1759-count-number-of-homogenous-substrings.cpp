class Solution {
public:
    int mod = 1e9+7;
    int solve(string s, int prevIdx, int idx) {
        if(idx >= s.size()) 
            return 0;
        int ans = 0;
        int cnt = 1;
        if(prevIdx == -1 || s[prevIdx] != s[idx])
            cnt = 1;
        if(prevIdx != -1 && s[prevIdx] == s[idx]) 
            cnt++;
        ans += cnt + solve(s, idx, idx + 1);
        return ans;

    }
    int countHomogenous(string s) {
        int ans = 0;
        int currStreak = 0;
        int MOD = 1e9 + 7;
        
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] == s[i - 1]) {
                currStreak++;
            } else {
                currStreak = 1;
            }
            
            ans = (ans + currStreak) % MOD;
        }
        
        return ans;
    }
};