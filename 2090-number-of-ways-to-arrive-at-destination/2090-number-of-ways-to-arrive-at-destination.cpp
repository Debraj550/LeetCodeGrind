class Solution {
public:
    int MOD = 1e9 + 7;

    int dijkstra(vector<vector<pair<int, int>>>& adjList, int src, int n) {
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        dist[src] = 0;
        ways[src] = 1;
        pq.push({0, src});

        while (!pq.empty()) {
            long long currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto& neighbor : adjList[node]) {
                int neighborNode = neighbor.first;
                long long edgeWeight = neighbor.second;

                if (currDist + edgeWeight < dist[neighborNode]) {
                    dist[neighborNode] = currDist + edgeWeight;
                    pq.push({dist[neighborNode], neighborNode});
                    ways[neighborNode] = ways[node];
                } else if (currDist + edgeWeight == dist[neighborNode]) {
                    ways[neighborNode] = (ways[neighborNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& road : roads) {
            adjList[road[0]].emplace_back(road[1], road[2]);
            adjList[road[1]].emplace_back(road[0], road[2]);
        }
        return dijkstra(adjList, 0, n);
    }
};
