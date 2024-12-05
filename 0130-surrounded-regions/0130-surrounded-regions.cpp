class Solution {
private:
    bool isSafe(int i, int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void DFS(int i, int j, vector<vector<char>>& board, vector<vector<int>>& directions, int n, int m) {  
        if(!isSafe(i, j, n, m) || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'F';
        for(auto& dir : directions) {
            int x = i + dir[0]; 
            int y = j + dir[1]; 
            DFS(x, y, board, directions, n, m); 
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();    
        int m = board[0].size(); 
        vector<vector<int>> directions = {
            {-1, 0},
            {0, -1}, {0, 1},
            {1, 0}  
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                    DFS(i, j, board, directions, n, m); 
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; 
                } else if (board[i][j] == 'F') {
                    board[i][j] = 'O'; 
                }
            }
        }
    }
};