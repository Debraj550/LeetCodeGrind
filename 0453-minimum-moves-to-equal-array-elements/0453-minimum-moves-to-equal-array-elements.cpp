class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            count += nums[i] - nums[0];
        }
        return count;
    }
};

/*
8 3 6 4 => 5 + 3 + 1 
8 4 7 5
8 5 8 6
8 6 9 7
8 7 10 8
8 8 11 9
9 9 11 10
10 10 11 11
11 11 11 12
12 12 12 12
*/
    
    

