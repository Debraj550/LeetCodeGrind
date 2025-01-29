class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, count = 0;
        int maxi = INT_MIN;
        while(i < nums.size()) {
            if(nums[i] != 1) {
                count = 0;
                i++;
            }
            if(i < nums.size() && nums[i] == 1 ) {
                count+=1;
                i++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};