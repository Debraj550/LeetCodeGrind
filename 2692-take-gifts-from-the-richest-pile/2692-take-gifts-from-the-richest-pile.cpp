class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto gift: gifts) pq.push(gift);
        long long ans = 0;
        int i = 0;
        while(k && !pq.empty()) {
            int maxPile = pq.top();
            pq.pop();
            int sqRoot = floor(sqrt(maxPile));
            pq.push(sqRoot);
            k--;
        }

        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};