class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(int i = 0; i < m; i++) {
            int ones = 0;
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) ones++;
            }
            pq.push({ones, i});
        }

        
        vector<int> res;
        while(k-- && !pq.empty()) {
           int row = pq.top().second;
           res.push_back(row);
           pq.pop();
       }
        return res;
    }
};