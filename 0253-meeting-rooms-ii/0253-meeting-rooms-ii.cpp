class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        /*sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        
        for (int i = 1; i < intervals.size(); i++) {
            
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        
        return pq.size();*/
        
        vector<pair<int,int>> timestamp;
        for(auto interval: intervals) {
            timestamp.push_back({interval[0],1});
            timestamp.push_back({interval[1],-1});
        }
        sort(timestamp.begin(), timestamp.end());
        int res = 0, count = 0;
        
        for(auto elem: timestamp) {
            count += elem.second;
            res = max(res, count);
        }
        return res;
    }
};

//