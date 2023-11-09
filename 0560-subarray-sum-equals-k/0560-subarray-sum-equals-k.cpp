class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = 1;
        for(auto x: nums) {
            sum += x;
            if(mp.find(sum-k) != mp.end()) 
                ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};