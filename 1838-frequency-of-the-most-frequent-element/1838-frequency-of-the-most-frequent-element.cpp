class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        long long total = 0;
        long long left = 0, right = 0;
        
        while(right < n) {
            total += nums[right];
            while( (right - left + 1) * nums[right] > total + k) {
                total -= nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        
        return ans;
    }
};