class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> contains;
        contains[0] = 1;
        int sum = 0;
        for(auto x: nums) {
            sum += x;
            if(contains[sum - k]) ans += contains[sum-k];
            contains[sum]++;
        }
        return ans;
    }
};