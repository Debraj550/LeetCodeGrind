class Solution {
public:
    bool bfs(int node, vector<int> &colors, vector<vector<int>> &graph) {
        queue<int> q;
        q.push(node);
        colors[node] = 0;
        while(!q.empty()) {
            int currNode = q.front();
            q.pop();
            int wantedNextColor = 1 - colors[currNode];
            for(auto neighbor: graph[currNode]) {
                if(colors[neighbor] == -1) {
                    colors[neighbor] = wantedNextColor;
                    q.push(neighbor);
                }
                if(colors[neighbor] == colors[currNode])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i = 0; i < n; i++) {
            if(colors[i] == -1 && !bfs(i, colors, graph)) 
                return false;
        }
        return true;
    }
};