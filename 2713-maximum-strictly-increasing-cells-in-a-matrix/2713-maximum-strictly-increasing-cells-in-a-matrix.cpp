class Solution {
public:
    
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, vector<vector<int>> > mp;
        vector<vector<int>> dp(m, vector<int>(n));
        set<int, greater<int>> st;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[mat[i][j]].push_back({i,j});
                st.insert(mat[i][j]);
            }
        }
        
        vector<int> r(m,0), c(n,0);
        for(auto ele: st) {
            for(auto cord: mp[ele]) {
                int i = cord[0];
                int j = cord[1];
                dp[i][j] = max(r[i], c[j]) + 1;
            }
            for(auto cord: mp[ele]) {
                int i = cord[0];
                int j = cord[1];
                r[i] = max(r[i], dp[i][j]);
                c[j] = max(c[j], dp[i][j]);
            }
            
        }
        return max(*max_element(r.begin(), r.end()), *max_element(c.begin(), c.end()) );
        
    }
};