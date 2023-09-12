class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int res = 0;

        int i = 0, j = 0;
        while(j < nums.size()) {
            if(nums[j] == 0) 
                zeroCount++;
            while(zeroCount > 1) {
                if(nums[i] == 0) zeroCount--;
                i++;
            }
            
            res = max(res, j - i);
            j++;
        }
        
        return res;
    }
};