class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int used = 0;
       int l = 0;
       int maxi = 0;

       for(int r = 0; r < nums.size(); r++) {
        while((used & nums[r]) != 0) {
            used ^= nums[l];
            l++;
        }
        used |= nums[r];
        maxi = max(maxi, r - l + 1);
       }
       return maxi;
    }
};


