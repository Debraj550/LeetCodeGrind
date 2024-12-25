class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto flight: flights)
            adj[flight[0]].push_back({flight[1], flight[2]});
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            int stop = temp.first;
            int node = temp.second.first;
            int price = temp.second.second;

            if(stop > k) continue;
            for(auto neighbor: adj[node]) {
                if(price + neighbor.second < dist[neighbor.first]) {
                    dist[neighbor.first] = price + neighbor.second;
                    q.push({stop + 1, {neighbor.first, price + neighbor.second}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};