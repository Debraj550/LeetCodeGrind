class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int,int>> mp;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(mp.find(ch) != mp.end()) {
                mp[ch].second = i;
            }
            else mp[ch] = {i, -1};
        }
        int ans = 0;
        for(auto x: mp) {
            unordered_set<char> between;
            if(x.second.second == -1) 
                continue; 
            for(int i = x.second.first + 1 ; i < x.second.second; i++) 
                between.insert(s[i]);
            ans += between.size();
        }
        
        return ans;
    }
};