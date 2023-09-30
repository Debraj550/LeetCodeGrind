class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        vector<int> minimumPref(nums.size());
        minimumPref[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            minimumPref[i] = min(minimumPref[i - 1], nums[i]);
        }
        
        int k = nums.size();
        for (int j = nums.size() - 1; j > 0; j--) {
            
            if (nums[j] <= minimumPref[j]) {
                continue;
            }
            while (k < nums.size() and nums[k] <= minimumPref[j]) {
                k++;
            }
            if (k < nums.size() and nums[k] < nums[j]) {
                return true;
            }
            nums[--k] = nums[j];
        }
        return false;
    }
};