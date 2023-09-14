class Solution {
    private:
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        vector<string> result;
    
        void dfs(string node)
        {
            auto & edges = graph[node];
            while (!edges.empty())
            {
                string adjNode = edges.top();
                edges.pop();
                dfs(adjNode);
            }
            result.push_back(node);
        }
    public:
        vector<string> findItinerary(vector<vector<string>> tickets) {
            for (auto e : tickets)
                graph[e[0]].push(e[1]);
            dfs("JFK");
            reverse(result.begin(), result.end());
            return result;
        }
};