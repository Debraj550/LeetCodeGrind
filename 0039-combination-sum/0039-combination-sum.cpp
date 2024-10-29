class Solution {
public:
    void solve(int x, vector<int> &candidates, int start, vector<vector<int>> &res, vector<int> &combination){
        if(x == 0) {
            res.push_back(combination);
            return;
        }
        if(x < 0) return;
        
        for(int i = start; i < candidates.size(); i++) {
            combination.push_back(candidates[i]);
            solve(x - candidates[i], candidates, i, res, combination);
            combination.pop_back();
        }
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        solve(target, candidates, 0, res, combination);
        return res;
    }
};