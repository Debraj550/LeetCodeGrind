class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find the peak element position
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else 
                right = mid;
        }
        int pivPos = left;
        //cout << pivPos << endl;
        left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            int pivMid = (mid + pivPos) % nums.size();
            
            if(nums[pivMid]== target)
                return pivMid;
            if(nums[pivMid] < target) 
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
        
    }
};