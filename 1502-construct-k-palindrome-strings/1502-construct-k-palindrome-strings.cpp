class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        unordered_map<char, int> mp;
        for(auto ch: s) mp[ch]++;
        int odd = 0;

        for(auto it: mp) {
            if(it.second%2 == 1) odd++;
        }

        return odd <= k;
    }
};