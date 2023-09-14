class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            long long avg = ceil((double)(sum)/(double)(i+1));
            ans = max(ans, avg);
        }
        return ans;
    }
};