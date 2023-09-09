class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int N = arr.size();
        vector<int> suf(N);
        vector<int> pref(N);
        suf[N-1] = 0;
        pref[0] = INT_MAX;
        
        for(int i = 1; i < N; i++) {
            pref[i] = min(arr[i-1], pref[i-1]);
        }
        
        for(int i = N-2; i>= 0; i--) {
            suf[i] = max(suf[i+1], arr[i+1]);
        }
        
        for(int i = 1; i < N-1; i++) {
            int curr = arr[i];
            if(curr > pref[i] && curr < suf[i]) {
                return true;
            }
        }
        return false;
    }
};