class Solution {
public:
    int mod = 1e9 + 7;
    
    int rev(int num) {
        int result = 0;
        while (num > 0) {
            result = result * 10 + num % 10;
            num /= 10;
        }
        
        return result;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for(auto num: nums){
            arr.push_back(num - rev(num));
        }
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto num: arr) {
            if(mp.find(num) != mp.end()) {
                ans = (ans +mp[num])%mod;
            }
            mp[num]++;
        }
        
        return ans;
    }
};