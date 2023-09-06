//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    class DSU {
      public:
      vector<int> parents;
      vector<int> sizes;
      int comps;
      DSU (int n) {
          for(int i = 0; i < n; i++) {
              parents.push_back(i);
              sizes.push_back(1);
          }
          comps = n;
      }
      
      int find(int x) {
          if(x == parents[x]) return x;
          return parents[x] = find(parents[x]);
      }
      
      int join(int u, int v) {
          u = find(u);
          v = find(v);
          if( u == v) return 0;
          
          if(sizes[u] < sizes[v]) {
              parents[u] = v;
              sizes[v] += sizes[u];
          }
          else{
              parents[v] = u;
              sizes[u] += sizes[v];
          }
          comps--;
          return 1;
      }
    };
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //adj = u -> v,w
        vector<vector<int>> edges;
        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                int u = i;
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt,u,v});
            }
            
        }
        
        //sort the edges by weight from smallest to largest
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0]<b[0];
        });
        
        int res = 0;
        DSU dsu(V);
        
        for(auto it: edges) {
            int wt = it[0];
            int u = it[1];
            int v = it[2];
            if(dsu.find(u) == dsu.find(v)) continue;
            else {
                res += wt;
                dsu.join(u,v);
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends