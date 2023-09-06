class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0) return true;
        if(m == 1 && n == 1) return true;
        
        //traverse first row and check for 1s if 1 found then reverse tat column
        for(int c = 0; c < n; c++) {
            if(grid[0][c] == 1) { 
                for(int r = 0; r < m; r++) {
                    grid[r][c] = 1 - grid[r][c];
                }
            }
        }
        
        for(int r = 1; r < m; r++) {
            int sum = 0;
            for(int c = 0; c < n; c++) {
                sum += grid[r][c];
            }
            if(sum == 0 || sum == n) continue;
            else return false;
        }
        
        return true;
        
    }
};