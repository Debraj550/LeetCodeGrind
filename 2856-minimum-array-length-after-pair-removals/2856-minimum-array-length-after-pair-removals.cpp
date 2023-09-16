class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto a: nums) mp[a]++;
        priority_queue<pair<int,int>> pq;
        
        for(auto it: mp) pq.push({it.second, it.first});
        
        while(pq.size() > 1) {
            int val1 = pq.top().first;
            int num1 = pq.top().second;
            pq.pop();
            int val2 = pq.top().first;
            int num2 = pq.top().second;
            pq.pop();
            
            val1--;
            val2--;
            
            if(val1) pq.push({val1, num1});
            if(val2) pq.push({val2, num2});
        }
        
        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top().first;
            pq.pop();
        }
        return ans;
        
        
    }
};