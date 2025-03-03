class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int lesser = 0;
        int greater = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            if (nums[i] < pivot) {
                ans[lesser] = nums[i];
                lesser++;
            }
            if (nums[j] > pivot) {
                ans[greater] = nums[j];
                greater--;
            }
        }
        while (lesser <= greater) {
            ans[lesser] = pivot;
            lesser++;
        }
        return ans;
    }
};