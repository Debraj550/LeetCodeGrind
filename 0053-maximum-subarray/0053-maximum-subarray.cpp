class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int curr = 0;
        for(auto num: nums) {
            curr = max(num, curr + num);
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};