class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = (n) * (n+1) / 2;
        int calSum = 0;
        for(auto num: nums) calSum+=num;
        return actualSum - calSum;
    }
};