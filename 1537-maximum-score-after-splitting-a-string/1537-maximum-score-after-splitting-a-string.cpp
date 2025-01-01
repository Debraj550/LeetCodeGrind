class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zeroCount(n, 0), oneCount(n, 0);
        zeroCount[0] = (s[0] == '0');
        for (int i = 1; i < n; i++) {
            zeroCount[i] = zeroCount[i - 1] + (s[i] == '0');
        }

        oneCount[n - 1] = (s[n - 1] == '1');
        for (int i = n - 2; i >= 0; i--) {
            oneCount[i] = oneCount[i + 1] + (s[i] == '1');
        }
        int maxScore = INT_MIN;
        for (int i = 1; i < n; i++) {
            int score = zeroCount[i - 1] + oneCount[i];
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};
