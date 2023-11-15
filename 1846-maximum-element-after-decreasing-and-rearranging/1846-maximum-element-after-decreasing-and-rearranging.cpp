class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans = 0;
        bool isSorted = true;
        if(arr[0] != 1) isSorted = false;
        int n = arr.size();
        if(n > 1) {
            for(int i = 1; i < n; i++) {
                if(abs(arr[i] - arr[i-1]) > 1) {
                    isSorted = false;
                    break;
                }
            }
        }
        if(!isSorted)
        {
            sort(arr.begin(), arr.end());
        }
        arr[0] = 1;
        int maxi = arr[0];
        for(int i = 1; i < n; i++) {
            if(abs(arr[i] - arr[i-1]) > 1) {
                    arr[i] = arr[i-1] + 1;
                }
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};