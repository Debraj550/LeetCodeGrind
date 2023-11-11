class Graph {
public:
   
    vector<vector<pair<int, int>>> adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v,wt});
        }
    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int n = adjList.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        
        vector<int> cost(n, INT_MAX);
        pq.push({0, node1});
        cost[node1] = 0;
        
        while (!pq.empty()) {
            int currCost = pq.top()[0];
            int currNode = pq.top()[1];
            pq.pop();

            if (currCost > cost[currNode]) {
                continue;
            }
            if (currNode == node2) {
                return currCost;
            }
            for (auto neighbor : adjList[currNode]) {
                int neighborNode = neighbor.first;
                int neighborCost = neighbor.second;
                int newCost = currCost + neighborCost;

                if (newCost < cost[neighborNode]) {
                    cost[neighborNode] = newCost;
                    pq.push({newCost, neighborNode});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */