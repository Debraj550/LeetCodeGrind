class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0, j = n;
        while(i < n && j < nums.size()) {
            nums[j] = nums[j] << 10;
            nums[j] = nums[j] | nums[i];
            i++;
            j++;
        }
        
        i = 0;
        for(j = n; j < nums.size(); j++) {
            int n1 = nums[j] & 1023;
            int n2 = nums[j] >> 10;
            nums[i] = n1;
            nums[i+1] = n2;
            i += 2;
        }
        return nums;
    }
};

/*
2 5 1 3 4 7
2 3 1 5 4 7
*/