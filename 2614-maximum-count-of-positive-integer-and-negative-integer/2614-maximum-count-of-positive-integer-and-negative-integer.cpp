class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int maxi = 0, mini = 0;
        for(auto num: nums) {
            if(num == 0) continue;
            if(num < 0) mini++;
            if(num > 0) maxi++;
        }
        return max(maxi, mini);
    }
};