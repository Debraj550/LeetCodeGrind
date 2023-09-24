//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool isValid(vector<vector<int>> &a, int n, int m, int i, int j, vector<vector<int>> &vis) {
        if(i >= n || j >= m || i < 0 || j < 0 || vis[i][j] == 1 || a[i][j] == 0) 
            return false;
        return true;
    }
    int shortestDistance(int n, int m, vector<vector<int>> a, int x, int y) {
        // code here
        if(a[0][0] == 0 || a[x][y] == 0) return -1;
        
        queue<pair<int, pair<int,int>> > q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dirs = {{0,1}, {1, 0}, {0,-1},{-1,0}};
        
        q.push({0, {0,0}});
        vis[0][0] = 1;
        int ans = -1;
        while(!q.empty()) {
            int dist = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            if(i == x && j == y) return dist;
            for(auto dir: dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                
                if(isValid(a,n,m,ni,nj,vis)) {
                    int newDist = 1 + dist;
                    q.push({newDist, {ni,nj}});
                    vis[ni][nj] = 1;
                }
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends