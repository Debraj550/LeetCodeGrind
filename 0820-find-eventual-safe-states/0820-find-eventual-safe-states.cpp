class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                adj[neighbor].push_back(i);  
                indegree[i]++;  
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int neighbor : adj[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(res.begin(), res.end());  
        return res;
    }
};
