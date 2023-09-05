class DSU {
  public:
    vector<int> parent;
    vector<int> size;
    int components;
    DSU (int n) {
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
        components = n;
    }
    
    int find(int x) {
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    
    int uf(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v)
            return 0;
        
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else{
            parent[v] = u;
            size[u]+=size[v];
        }
        components--;
        return 1;
    }
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        DSU dsu(n);
        sort(logs.begin(), logs.end());
        for(auto log: logs) {
            int timestamp = log[0];
            int a = log[1];
            int b = log[2];
            dsu.uf(a,b);
            dsu.uf(b,a);
            if(dsu.components == 1)
                return timestamp;
            
        }
        return -1;
    }
};