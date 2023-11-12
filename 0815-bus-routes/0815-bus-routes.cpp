
class Solution {
public:

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if (source == target) 
            return 0;
        
        unordered_map<int, vector<int>> adjList;
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                adjList[stop].push_back(route);
            }
        }
        
  
        
        queue<int> q;
        unordered_set<int> vis;
        for(auto route: adjList[source]) {
            q.push(route);
            vis.insert(route);
        } 
        
        int bus = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int route = q.front();
                q.pop();
                
                for(auto stop: routes[route]) {
                    if(stop == target) return bus;
                    for(auto nextRoute: adjList[stop]) {
                        if(!vis.count(nextRoute)) {
                            vis.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            bus++;
        }
        return -1;
        
    }
};