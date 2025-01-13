class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int, int> mp;
        for(auto num: nums) mp[num]++;

        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        vector<int> res;
        while(!pq.empty() && k--) {
            auto top = pq.top();
            res.push_back(top.second);
            pq.pop();
        }

        return res;
    }
};