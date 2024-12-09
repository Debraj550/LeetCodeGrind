class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n, 0);

        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1];
            if( (nums[i-1] % 2 == 0 && nums[i] % 2 ==0) || (nums[i] % 2 != 0 && nums[i-1] % 2 != 0))
                pref[i]++;
        }

        vector<bool> res;
        for(auto query: queries) {
            int l = query[0];
            int r = query[1];
            int special = pref[r] - (pref[l] > 0 ? pref[l] : 0);
            res.push_back(special == 0);
        }
        return res;
    }
};