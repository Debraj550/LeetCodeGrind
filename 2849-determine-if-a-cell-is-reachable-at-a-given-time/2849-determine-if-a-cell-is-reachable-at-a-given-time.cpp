class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int cols = abs(sx - fx);
        int rows = abs(sy - fy);
        if(t == 1 && rows + cols == 0) return false;
        int miniMoves = max(rows, cols);
        return miniMoves <= t;
        
        
    }
};