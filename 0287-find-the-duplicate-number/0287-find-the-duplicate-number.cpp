class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> seen;
        for(auto x: nums) {
            if(seen.find(x) != seen.end()) return x;
            seen.insert(x);
        }
        return -1;
    }
};