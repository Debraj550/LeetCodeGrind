class Solution {
public:
    int solve(vector<int> &nums, int idx, int maxi, int mini) {
        if(idx >= nums.size()) return maxi;

        int curr = nums[idx];

        int maxTillNow = max({curr, curr * maxi, curr * mini});
        int minTillNow = min({curr, curr * maxi, curr * mini});

        return max(maxTillNow, solve(nums, idx + 1, maxTillNow, minTillNow));
    }
    int maxProduct(vector<int>& nums) {
        // int curr = nums[0];
        // int maxi = nums[0];
        // int mini = nums[0];
        
        // for(int i = 1; i < nums.size(); i++) {
        //     int prod = max(nums[i], max(nums[i] * maxi, nums[i] * mini));
        //     mini = min(nums[i], min(nums[i] * maxi, nums[i] * mini));
        //     maxi = prod;
        //     curr = max(maxi, curr);
        // }
        // return curr;

        return solve(nums, 0, 1, 1);
    }
};