class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int curr = 0;
        int start = 0, end;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > nums[i] + curr) {
                curr = nums[i];
                start = i;
            }
            else curr = nums[i] + curr;
            if(curr > maxi) {
                maxi = curr;
                end = i;
            }
        }
        cout << start << " - " << end << endl;
        return maxi;
    }
};