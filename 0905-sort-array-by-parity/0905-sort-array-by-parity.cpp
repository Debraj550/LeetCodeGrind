class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int k = 0, j = n-1;
        for(int i = 0; i < n; i++) {
            if(nums[i]%2) ans[j--] = nums[i];
            else ans[k++] = nums[i];
        }
        return ans;
    }
};