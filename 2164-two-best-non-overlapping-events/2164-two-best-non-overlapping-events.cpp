class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int maxValue = 0;
        int res = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int,int>>> > pq;
        
        for(int i = 0; i < events.size(); i++) {
            while(!pq.empty() && pq.top().first < events[i][0] ) {
                maxValue = max(maxValue, pq.top().second.second);
                pq.pop();
            }

            pq.push({events[i][1], {events[i][0], events[i][2]}});
            res = max(res, maxValue + events[i][2]);
        }

        return res;
    }
};