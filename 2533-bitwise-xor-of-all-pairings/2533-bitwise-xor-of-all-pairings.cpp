class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;

        if(nums2.size()%2)
            for(auto num: nums1) res ^= num;
        if(nums1.size()%2)
            for(auto num: nums2) res ^= num;
        return res;
    }
};