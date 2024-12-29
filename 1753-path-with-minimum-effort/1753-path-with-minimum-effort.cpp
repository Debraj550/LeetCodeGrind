class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {0, 1}, {-1,0}, {0, -1}};
    bool isValid(int x, int y, vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        if(x < 0 || y < 0 || x >= n || y >= m) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int> > > > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int currDist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            int currHeight = heights[i][j];
            for(auto dir: dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(isValid(ni, nj, heights)) {
                    int adjHeight = heights[ni][nj];
                    int absDiff = max(abs(adjHeight - currHeight), currDist);
                    if(absDiff < dist[ni][nj] ) {
                        dist[ni][nj] = absDiff;
                        pq.push({absDiff, {ni, nj}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};