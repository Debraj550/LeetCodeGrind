class DSU {
public:
    int comps;
    vector<int> parent;
    vector<int> sizes;
    DSU(int n) {
        comps = n;
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            sizes.push_back(1);
        }
    }
    
    int findPar(int x){
        if(x == parent[x]) return x;
        return parent[x] = findPar(parent[x]);
    }
    
    int uf(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return 0;
        if(sizes[u] < sizes[v]) {
            parent[u] = v;
            sizes[v] += sizes[u];
        }
        else {
            parent[v] = u;
            sizes[u]+=sizes[v];
        }
        comps--;
        return 1;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int p = points.size();
        vector<vector<int>> edges;
        
        for(int i = 0; i < p; i++) {
            vector<int> p1 = points[i];
            for(int j = i+1; j < p; j++) {
                vector<int> p2 = points[j];
                int dist = abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
                vector<int> temp;
                temp.push_back(dist);
                temp.push_back(i);
                temp.push_back(j);
                edges.push_back(temp);
            }
        }
        sort(edges.begin(), edges.end());
        
        DSU dsu(p);
        int cost = 0;
        int edgesUsed = 0;
        
        for(auto edge: edges) {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            if(dsu.uf(u,v)) {
                cost += wt;
                edgesUsed++;
            }
            if(edgesUsed == p - 1) break;
        }
        return cost;
    }
};