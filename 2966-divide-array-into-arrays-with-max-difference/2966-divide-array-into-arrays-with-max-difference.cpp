class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result(n/3, vector<int>(3, 0));
        int flag = 1;
        if(n%3 != 0) return {};            
        for(int i = 0; i < n ; i+=3) {
            if(i + 2 > n) break;
            if(nums[i+2] - nums[i] > k) {
                flag = 0;
                break;
            }
        }
        int l = 0, r = 0;
        if(flag == 0) return {};
        for(int i = 0; i < n; i++) {
            if(r > 2) r = 0;
            result[i/3][r] = nums[i];
            r++;
        }
        
        return result;
    }
};