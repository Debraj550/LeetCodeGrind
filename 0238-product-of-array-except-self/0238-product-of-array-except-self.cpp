class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size(), 1);
        pref[0] = 1;
        int prod = 1;
        for(int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i-1] * nums[i-1];
        }

        prod = 1;
        for(int i = nums.size() - 1 ; i >= 0; i--) {
           pref[i] = pref[i] * prod;
           prod = prod * nums[i];
        }
        return pref;
        
    }
};