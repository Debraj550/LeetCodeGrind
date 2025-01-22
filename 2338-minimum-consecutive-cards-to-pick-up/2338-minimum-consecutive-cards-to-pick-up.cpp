class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int res = INT_MAX;
        for(int i = 0; i < cards.size(); i++) {
            int card = cards[i];
            if(mp.find(card)!= mp.end()) {
                res = min(res, i - mp[card] + 1);
                mp[card] = i;
            }
            else mp[card] = i;
        }

        return res == INT_MAX ? -1: res;
    }
};


