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
        
        vector<int> start, end;
        for(auto interval: intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int s = 0, e = 0;
        int res = 0, count = 0;
        
        while(s < start.size()) {
            if(start[s] < end[e]) {
                count += 1;
                s++;
            }
            else {
                count -= 1;
                e++;
            }
            res = max(res, count);
        }
        
        return res;
    }
};

//