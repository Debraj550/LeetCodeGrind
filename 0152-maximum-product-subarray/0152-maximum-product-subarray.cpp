class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr = nums[0];
        int maxi = nums[0];
        int mini = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            int prod = max(nums[i], max(nums[i] * maxi, nums[i] * mini));
            mini = min(nums[i], min(nums[i] * maxi, nums[i] * mini));
            maxi = prod;
            curr = max(maxi, curr);
        }
        return curr;
    }
};