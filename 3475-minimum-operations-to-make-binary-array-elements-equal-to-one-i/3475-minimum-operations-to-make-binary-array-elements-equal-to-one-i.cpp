class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i - 2] == 0) {
                count++;
                nums[i - 2] = 1 - nums[i-2];
                nums[i - 1] = 1 - nums[i-1];
                nums[i] = 1 - nums[i];
            }
        }
        
        for(auto num: nums) if(num==0) return -1;
        return count;
    }
};