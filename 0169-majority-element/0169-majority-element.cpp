class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(count == 0) {
                el = nums[i];
            }
            if(el == nums[i]) count++;
            else count--;
        }
        count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == el) count++;
        }

        return count > nums.size()/2 ? el: -1;
    }
};