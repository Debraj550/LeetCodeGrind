class Solution {
public:
    vector<vector<int>> dirs = { {1, 0}, {0, 1}, {-1,0}, {0,-1} };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int freshOranges = 0;

        for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == 2) 
                        q.push({i,j});
                    if(grid[i][j] == 1) freshOranges++;
                }
            }

        int time = 0;
        while(!q.empty() && freshOranges > 0) {
            int qSize = q.size(); 
            while(qSize--) { 
                pair<int,int> currentPos = q.front();
                q.pop();
                int currentX = currentPos.first;
                int currentY = currentPos.second;
                for(auto dir: dirs) {
                   int newX = currentX + dir[0];
                    int newY = currentY + dir[1];
                    if(newX >= m || newX < 0 || newY >= n || newY < 0 || grid[newX][newY] != 1)
                        continue;
                    grid[newX][newY] = 2;
                    q.push({newX, newY});
                    freshOranges--;
                }
            }
            time++;
        }

        return freshOranges > 0 ? -1 : time;
 }

};