class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1, 0}, {-1,0}, {0, -1}};
    void dfs(int i, int j, int m, int n, vector<vector<int>> &visited, vector<vector<int>> &grid) {
        if(i < 0 || i == m-1 || j < 0 || j == n-1 || visited[i][j] == 1 || grid[i][j] == 0)
            return;
        visited[i][j] = 1;
        for(auto dir: dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            dfs(ni, nj, m, n, visited, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m =  grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i * j == 0 || i == m-1 || j == n-1) {
                    if(grid[i][j] == 1) 
                        dfs(i,j,m,n, visited, grid);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !visited[i][j])
                    res++;
            }
        }
        return res;

    }
};