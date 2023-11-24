class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int choices = n / 3;
        sort(piles.begin(), piles.end());
        int j = n - 2;
        int sum = 0;
        while(j >= 0 && choices--) {
            sum += piles[j];
            j = j - 2;
        }
        return sum;
    }
};

