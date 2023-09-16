class Solution {
public:
    bool isValid(int i,int j, int n, int m) {
        if(i < 0 || j < 0 || i == n || j == m) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        int n = heights.size();
        int m = heights[0].size();
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q;
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        q.push({0, {0,0}});
        distance[0][0] = 0;

        while(!q.empty()) {
            int dist = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
            int currHeight = heights[i][j];
            q.pop();
            
            for(auto dir: directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(isValid(ni,nj, n, m)) {
                    int newHeight = heights[ni][nj];
                    int diff = max(abs(newHeight-currHeight),dist);
                    cout << diff << endl;
                    if(diff < distance[ni][nj] ) {
                        distance[ni][nj] = diff;
                        q.push({distance[ni][nj],{ni,nj}});
                    }
                }
            }
        }

        return distance[n-1][m-1];


    }
};