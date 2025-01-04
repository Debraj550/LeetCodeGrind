class Solution {
public:
    unordered_map<string, int> cache;
    
    int solve(vector<vector<int>> &triangle, int m, int row, int col) {
        if (row >= m) return 0;
        string cacheKey = to_string(row) + "-" + to_string(col);
        if (cache.find(cacheKey) != cache.end()) return cache[cacheKey];
        int currVal = triangle[row][col];
        int result = currVal + min(
            solve(triangle, m, row + 1, col),
            solve(triangle, m, row + 1, col + 1)
        );
        return cache[cacheKey] = result;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, triangle.size(), 0, 0);
    }
};
