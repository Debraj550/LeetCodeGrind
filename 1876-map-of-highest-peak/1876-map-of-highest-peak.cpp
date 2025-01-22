class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1},{-1,0}};

    bool isValid(int m, int n, int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n) ? true: false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        
        vector<vector<int>> heights(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j]) {
                    heights[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int nextHeight = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto currCell = q.front();
                q.pop();
                for(auto dir: dirs) {
                    int nr = currCell.first + dir[0];
                    int nc = currCell.second + dir[1];
                    if(isValid(m, n, nr, nc) && heights[nr][nc] == -1) {
                        heights[nr][nc] = nextHeight;
                        q.push({nr, nc});
                    }
                }
            }
            nextHeight++;
        }

        return heights;

    }
};