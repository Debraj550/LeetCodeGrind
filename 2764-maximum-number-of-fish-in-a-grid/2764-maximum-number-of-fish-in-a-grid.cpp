class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    bool isValid(int m, int n, int i, int j, vector<vector<int>> &visited, vector<vector<int>> &grid) {
        if (i < m && i >= 0 && j < n && j>=0 && !visited[i][j] && grid[i][j] != 0) 
            return true;
        return false;
    }
    int bfs(vector<vector<int>> &grid, int m, int n, int i, int j, vector<vector<int>> &visited) {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        int val = 0;
        while(!q.empty()) {
            int celli = q.front().first;
            int cellj = q.front().second;
            q.pop();
            val += grid[celli][cellj];
            for(auto dir: dirs) {
                int ni = celli + dir[0];
                int nj = cellj + dir[1];
                if(isValid(m,n,ni,nj,visited,grid)) {
                    visited[ni][nj] = 1;
                    q.push({ni,nj});
                }
            }
        }
        return val;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi = INT_MIN;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0 || visited[i][j]) continue;
                maxi = max(maxi, bfs(grid, m, n, i, j, visited));
            }
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};