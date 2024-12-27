class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxScore = 0;
        int maxi = values[0] + 0;
        for(int i = 1; i < n; i++) {
            maxScore = max(maxScore, maxi + values[i] - i);
            maxi = max(maxi, values[i] + i);
        }
        return maxScore;
    }
};