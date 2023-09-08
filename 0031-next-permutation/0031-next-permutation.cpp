class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(i = n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) 
                break;
        }
        if(i < 0)
            reverse(nums.begin(), nums.end());
        else {
            int j = n- 1;
            while(j > i) {
                if(nums[j] > nums[i])
                    break;
                j--;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};