class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        int maxi = (m * n);
        vector<vector<int>> heights(m, vector<int>(n, maxi));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j]) heights[i][j] = 0; 
            }
        }


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int dist = maxi;
                int ni = i - 1;
                int nc = j;
                if(ni >= 0 && ni < m && nc >= 0 && nc < n ) {
                    dist = min(dist, heights[ni][nc]);
                }

                ni = i;
                nc = j - 1;
                if(ni >= 0 && ni < m && nc >= 0 && nc < n ) {
                    dist = min(dist, heights[ni][nc]);
                }

                heights[i][j] = min(heights[i][j], dist + 1);
            }
        }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int dist = maxi;
                int ni = i + 1;
                int nj = j;
                if(ni >= 0 && ni < m && nj >= 0 && nj < n ) {
                    dist = min(dist, heights[ni][nj]);
                }
                ni = i;
                nj = j + 1;
                if(ni >= 0 && ni < m && nj >= 0 && nj < n ) {
                    dist = min(dist, heights[ni][nj]);
                }

                heights[i][j] = min(heights[i][j], dist + 1);
            }
        }

        return heights;

    }
};