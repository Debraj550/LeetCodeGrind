class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { 
        int pos1 = bs(nums, target);
        int pos2 = bs(nums, target+1)-1;
        if(nums.size() == 0)
            return {-1, -1};
        
        if (pos1 < nums.size() && nums[pos1] == target) 
            return {pos1, pos2};
        else 
            return {-1, -1};
    }

    int bs (vector<int> &nums, int target) {
        int  l = 0; 
        int r = nums.size() - 1;
        while (l <= r) 
        {
            int mid = l + (r-l)/2;
            if (nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
};