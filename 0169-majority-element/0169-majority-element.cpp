class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el, count = 0;
        for (int num : nums) {
            if (count == 0) {
                el = num;
            }
            count += (num == el) ? 1 : -1;
        }

        count = 0;
        for (int num : nums) {
            if (num == el) count++;
        }
        return count > nums.size() / 2 ? el : -1;
    }
};
