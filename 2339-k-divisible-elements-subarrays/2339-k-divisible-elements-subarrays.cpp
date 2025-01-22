class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            vector<int> curr;
            int count = 0;
            for(int j = i; j < n; j++) {
                if(nums[j]%p==0) count++;
                if(count > k) break;
                curr.push_back(nums[j]);
                st.insert(curr);
            }
        }

        return st.size();
    }
};