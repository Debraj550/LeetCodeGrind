class Solution {
public:
    int findDiscount(int idx, int price, vector<int> &prices) {
        while(idx < prices.size()) {
            int selectedPrice = prices[idx];
            if(selectedPrice <= price) 
                return selectedPrice;
            idx++;
        }
        return 0;
    }
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        for(int i = 0; i < prices.size(); i++) {
            int currentPrice = prices[i];
            int discountedPrice = findDiscount(i+1, currentPrice, prices);
            res.push_back(currentPrice - discountedPrice);
        }
        return res;
    }
};