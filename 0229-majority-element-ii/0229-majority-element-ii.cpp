class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0, c2 = 0;
        int x = -1, y = -1;
        
        for(auto num: nums) {
            if(x == num) c1++;
            else if(y == num) c2++;
            else if(c1 == 0) {
                x = num;
                c1 = 1;
            }
            else if(c2 == 0) {
                y = num;
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }
        
        vector<int> res;
        c1 = 0;
        c2 = 0;
        for(auto num: nums) {
            if(num == x) c1++;
            else if(num == y) c2++;
        }
        if(c1 > n/3) res.push_back(x);
        if(c2 > n/3) res.push_back(y);
        return res;
    }
};