class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c = nums[0];
        int d = nums[1];
        int a = nums[nums.size() - 1];
        int b = nums[nums.size() - 2];
        
        return (a*b) - (c*d);
    }
};