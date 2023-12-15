class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> mp;
        for (int i = 0; i < paths.size(); i++) {
            mp.insert(paths[i][0]);
        }
        
        for (int i = 0; i < paths.size(); i++) {
            string x = paths[i][1];
            if (mp.find(x) == mp.end()) {
                return x;
            }
        }
        
        return "";
    }
};