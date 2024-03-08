class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxFreq = 0;
        for(auto num: nums) {
            mp[num]++;
            maxFreq = max(maxFreq, mp[num]);
        }
        
        int ans = 0;
        for(auto num: nums) {
            if(mp[num] == maxFreq) ans++;
        }
        
        return ans;
    }
};