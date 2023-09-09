typedef long long ll;
class Solution {
private:
    ll kadane(vector<int> &arr) {
        ll maxSum = 0;
        ll currSum = 0;
        for(auto a: arr) {
            currSum = max((ll)a, (ll)currSum + (ll)a);
            maxSum = max(currSum, maxSum);
        }
        
        return maxSum;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll mod = 1e9+7;
        ll sum = 0;
        for(auto a: arr) sum+=a;
        if(k == 1)
            return kadane(arr);
        
        vector<int> newarr = arr;
        for(auto a: arr) newarr.push_back(a);
        
        if(sum < 0) {
            return kadane(newarr)%mod;;
        }
        
        if(sum >= 0) {
            return (kadane(newarr)%mod + ((k-2) * sum % mod) % mod ) % mod;
        }

        return -1;
    }
};