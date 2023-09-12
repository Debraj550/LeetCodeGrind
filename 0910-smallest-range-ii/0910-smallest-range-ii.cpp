class Solution {
private: 
    int maxi, mini;
    int res;
    void solve(vector<int> &nums, int idx, int k) {
        if(idx == nums.size()) {
            maxi = *max_element(nums.begin(), nums.end());
            mini = *min_element(nums.begin(), nums.end());
            res = min(res, abs(maxi-mini));
            return;
        }
        nums[idx] += k;
        solve(nums, idx + 1, k);
        nums[idx]-=k;
        nums[idx]-=k;
        solve(nums, idx + 1, k);
        nums[idx]+=k;
    }
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int res = A[A.size() - 1] - A[0];
        int left = A[0] + K, right = A[A.size() - 1] - K;
        
        for (int i = 0; i < A.size() - 1; i++) {
            int maxi = max(A[i] + K, right);
            int mini = min(left, A[i + 1] - K);
            res = min(res, maxi - mini);
        }
        return res;
    }
};

/*

1 3 6


*/