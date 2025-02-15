class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> st, res(n, -1);
        for(int i = 0; i < n * 2; i++) {
            while(st.size() && nums[st.back()] < nums[i%n]) {
                res[st.back()] = nums[i%n];
                st.pop_back();
            }
            st.push_back(i%n);
        }
        return res;
    }
};