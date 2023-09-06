class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        sort(flights.begin(), flights.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        
        vector<pair<int,int>> adj[n];
        for(auto edge: flights) {
            int u = edge[0];
            int v = edge[1];
            int price = edge[2];
            adj[u].push_back({v,price});
        }
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k)
                continue;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;
                if (cost + edW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
        
    }
};