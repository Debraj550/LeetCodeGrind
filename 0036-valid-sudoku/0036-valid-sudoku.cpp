class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowset(9);
        vector<unordered_set<char>>  colset(9);
        vector<unordered_set<char>> subboxset(9);
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                
                if(board[i][j] != '.') {
                    int k = i / 3 * 3 + j / 3;
                    if(rowset[i].find(board[i][j]) != rowset[i].end() || 
                       colset[j].find(board[i][j]) != colset[j].end() ||
                       subboxset[k].find(board[i][j]) != subboxset[k].end())
                        return false;

                    rowset[i].insert(board[i][j]);
                    colset[j].insert(board[i][j]);
                    subboxset[k].insert(board[i][j]);
                }
                
            }
        }
        
        return true;
    }
};