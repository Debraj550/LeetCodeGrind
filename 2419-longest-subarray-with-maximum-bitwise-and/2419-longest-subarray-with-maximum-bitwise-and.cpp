class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int maxi = 0;
        int len = 0;
        
        for(auto num: nums) {
            if(maxi < num) {
                maxi = num;
                len = 0;
                ans = 0;
            }
            
            if(maxi == num) {
                len++;
            }
            else {
                len = 0;
            }
            
            ans = max(ans, len);
        }
        
        
        return ans;
    }
};