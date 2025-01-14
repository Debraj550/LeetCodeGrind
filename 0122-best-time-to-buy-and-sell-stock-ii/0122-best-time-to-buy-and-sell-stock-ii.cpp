class Solution {
public:
    int maxProfit(vector<int>& prices) {
        prices.push_back(-1);
        int profit=0;
        int sum=0;
        if(prices.size()==1)
            return 0;
        int currentprice=prices[0];
        for(int i=1;i<prices.size();i++){
            currentprice=min(prices[i],currentprice);
            profit=prices[i]-currentprice;
            if(profit>0 && (prices[i+1]<prices[i])){
                currentprice=prices[i+1];
                sum+=profit;
                if(currentprice==-1)
                    break;               
            }
        }
        return sum;
    }
};