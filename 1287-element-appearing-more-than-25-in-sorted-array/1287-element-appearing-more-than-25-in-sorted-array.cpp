class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int desiredCount = n/4;
        unordered_map<int,int> mp;
        for(auto x: arr) {
            mp[x]++;
            if(mp[x] > desiredCount) return x;
        }
        return -1;
    }
};