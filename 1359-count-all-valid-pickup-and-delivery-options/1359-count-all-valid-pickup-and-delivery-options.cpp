class Solution {
public:
   
    int countOrders(int n) {
        long long ans = 1;
        int mod = 1e9+7;
        int slots = 2 * n;
        
        while(slots) {
            long long validChoices = (slots * (slots - 1) / 2)%mod;
            ans =  ans % mod * validChoices % mod;
            slots -= 2;
        }
        return ans%mod;
    }
};