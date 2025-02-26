class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxPref = 0;
        int minPref = 0;
        int curr = 0;
        int res = 0;

        for(int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            maxPref = max(maxPref, curr);
            minPref = min(minPref, curr);
            res = max({res, abs(curr - maxPref), abs(curr - minPref)});
        }
        
        return res;
    }
};