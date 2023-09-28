class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        while(i < j) {
            int num1 = nums[i];
            int num2 = nums[j];
            if(num1%2 == 1 && num2%2 == 0) swap(nums[i],nums[j]);
            if(nums[i]%2 == 0) i++;
            if(nums[j]%2 == 1) j--;
        }
        return nums;
    }
};