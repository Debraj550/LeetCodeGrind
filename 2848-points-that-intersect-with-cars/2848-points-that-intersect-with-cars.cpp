class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> temp;
        temp.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++) {
            vector<int> num = nums[i];
            if(num[0] > temp.back()[1]) {
                temp.push_back(num);
            }
            else temp.back()[1] = max(temp.back()[1], num[1]);
        }
        
        int ans = 0;
        for(auto num: temp){
            ans += (num[1] - num[0] + 1);
        }
        return ans;
    }
};