class Solution {
public:
    void solve(int x, vector<int> &candidates, int start, vector<vector<int>> &res, vector<int> &combination){
        if(x == 0) {
            res.push_back(combination);
            return;
        }
        
        for(int i = start; i < candidates.size() && x >= candidates[i]; i++) {
            if(i != start && candidates[i] == candidates[i-1] ) continue;
            else {
                combination.push_back(candidates[i]);
                solve(x - candidates[i], candidates, i+1, res, combination);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        solve(target, candidates, 0, res, combination);
        return res;
    }
};