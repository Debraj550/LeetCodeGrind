class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        long long score = 0;

        while(!pq.empty()) {
            int smallest = pq.top().first;
            int smallestIdx = pq.top().second;
            pq.pop();
            if(nums[smallestIdx] != -1) {
                score += smallest;
                nums[smallestIdx] = -1;
                if(smallestIdx > 0) nums[smallestIdx-1] = -1;
                if(smallestIdx < nums.size() - 1) nums[smallestIdx + 1] = -1; 
            }
        }

        return score;

    }
};