class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<vector<vector<int>>> sQ(heights.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> res(queries.size(), -1);

        for(int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if(a < b && heights[a] < heights[b]) res[i] = b;
            else if(a > b && heights[a] > heights[b]) res[i] = a;
            else if(a == b) res[i] = b;
            else {
                sQ[max(a, b)].push_back({max(heights[a], heights[b]), i});
            }
        }

        for(int i = 0; i < heights.size(); i++) {
            while(!pq.empty() && pq.top()[0] < heights[i]) {
                res[pq.top()[1]] = i;
                pq.pop();
            }
            for(auto &ele: sQ[i]) pq.push(ele);
        }
        return res;
    }
};