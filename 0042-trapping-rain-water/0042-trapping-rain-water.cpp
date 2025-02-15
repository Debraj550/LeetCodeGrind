class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = height[r];

        while(l < r) {
            // left height <= right hegight, l++
            if(height[l] <= height[r]) {
                if(height[l] < leftMax) ans += leftMax - height[l];
                else leftMax = height[l];
                l++;
            }

            // viceversa, r--
            else {
                if(height[r] < rightMax) ans += rightMax - height[r];
                else rightMax = height[r];
                r--;
            }
        }

        return ans;
    }
};