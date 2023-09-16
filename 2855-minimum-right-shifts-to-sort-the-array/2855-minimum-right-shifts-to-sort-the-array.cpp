class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i+1 < n && nums[i] < nums[i+1]) i++;
        if(i == n-1) return 0;
        
        int piv = i;
        i++;
        cout << nums[piv] << endl;
        while(i+1 < n && nums[i] < nums[i+1]) i++;
        if(i == n-1) {
            if(nums[piv] >= nums[0] && nums[0] > nums[n-1]) return n - piv - 1 ;
            else return -1;
        }
        return -1;
    }
};