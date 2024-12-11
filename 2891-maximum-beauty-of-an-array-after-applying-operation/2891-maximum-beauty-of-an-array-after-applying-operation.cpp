class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int r = 0;  
        int ans = 0;
        for (int l = 0; l < nums.size(); l++) {
            while (r < nums.size() && nums[r] - nums[l] <= 2 * k) {
                r++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};