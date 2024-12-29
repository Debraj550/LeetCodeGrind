class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>> &grid) {
        int n = grid.size();
        if(x <  0 || y < 0 || x >= n || y >= n || grid[x][y] == 1) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; 
        distance[0][0] = 1;
        pq.push({1, {0,0}});
        
        while(!pq.empty()) {
            int dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(auto dir: directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(isValid(ni, nj, grid) && dist + 1 < distance[ni][nj]) {
                    distance[ni][nj] = 1 + dist;
                    pq.push({1+dist, {ni, nj}});
                }
            }
        }

        return distance[n-1][n-1] == INT_MAX ? -1 : distance[n-1][n-1] ;

    }
};