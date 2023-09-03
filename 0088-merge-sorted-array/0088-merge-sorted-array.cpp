class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m-1;
        int k = n-1;
        int i = nums1.size()- 1;
        while(j >= 0 && k >= 0) {
            if(nums1[j] > nums2[k]) {
                nums1[i] = nums1[j];
                i--;
                j--;
            }
            else {
                nums1[i] = nums2[k];
                i--;
                k--;
            }
        }

        while(j>=0){
            nums1[i--] = nums1[j--];
        }
        while(k >= 0) {
            nums1[i--] = nums2[k--];
        }
        
    }
};