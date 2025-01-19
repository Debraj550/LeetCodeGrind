class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1, 0}, {-1,0}};

    bool isValid(int row, int col, int numRows, int numCols) {
        return row >= 0 && row < numRows && col >= 0 && col < numCols;
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        minCost[0][0] = 0;
        while(!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for(int dir = 0; dir < 4; dir++) {
                int nr = r + dirs[dir][0];
                int nc = c + dirs[dir][1];
                int cost = (grid[r][c] != (dir + 1)) ? 1: 0;
                
                if(isValid(nr, nc, m, n) && minCost[r][c] + cost < minCost[nr][nc]) {
                    minCost[nr][nc] = minCost[r][c] + cost;
                    if(cost == 1) dq.push_back({nr, nc});
                    else dq.push_front({nr, nc});
                }

            }
        }
        return minCost[m-1][n-1];

    }
};