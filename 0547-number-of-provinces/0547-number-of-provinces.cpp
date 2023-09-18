class DSU {
    public:
        vector<int> parents;
        vector<int> sizes;
        int components;
    
        DSU(int n) {
            for(int i = 0; i < n; i++) {
                parents.push_back(i);
                sizes.push_back(1);
            }
            components = n;
        }
    
        int find(int node) {
            if(node == parents[node]) 
                return node;
            return parents[node] = find(parents[node]);
        }
    
        int uf(int u, int v) {
            u = find(u);
            v = find(v);
            
            if(u == v) return 0;
            
            if(sizes[u] < sizes[v]) {
                parents[u] = v;
                sizes[v] += sizes[u];
            }
            else {
                parents[v] = u;
                sizes[u] += sizes[v];
            }
            components--;
            return 1;
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    dsu.uf(i,j);
                }
            }
        }
        return dsu.components;
        
    }
};