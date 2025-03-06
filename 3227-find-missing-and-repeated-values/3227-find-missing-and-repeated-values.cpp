class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int a = -1, b = -1;
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[grid[i][j]]++;
            }
        }
        int temp = 1;
        for(auto x: mp) {
            if(x.second == 2) a = x.first;
        }
        while(mp.find(temp) != mp.end()) {
            temp++;
        }
        return {a, temp};
    }
};