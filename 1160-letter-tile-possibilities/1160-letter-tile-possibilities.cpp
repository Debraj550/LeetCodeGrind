class Solution {
public:
    int solve(string &tiles, vector<bool> &used) {
        int res = 0;

        for(int i = 0; i < tiles.size(); i++) {
            if(used[i] || (i > 0 && tiles[i-1] == tiles[i] && !used[i-1])) continue;
            used[i] = true;
            res += 1 + solve(tiles, used);
            used[i] = false;
        }

        return res;

    } 
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.size(), false);
        return solve(tiles, used);
    }
};