class Solution {
public:
    void dfs(int curr, int prev, vector<int> &ans, unordered_map<int, vector<int>> &graph) {
        ans.push_back(curr);
        for(auto n: graph[curr]){
            if(n != prev) {
                dfs(n, curr, ans, graph);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {        
        unordered_map<int, vector<int>> graph;
        for (auto& edge : adjacentPairs) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int root = 0;
        for (auto pair : graph) {
            if (pair.second.size() == 1) {
                root = pair.first;
                break;
            }
        }
        
        vector<int> ans;
        dfs(root, INT_MAX, ans, graph);
        return ans;
    }
};

/*
2 -> 1
3 -> 4
3 -> 2

*/