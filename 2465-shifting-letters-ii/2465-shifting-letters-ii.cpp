class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftDelta(n + 1, 0);
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];

            shiftDelta[start] += (dir == 1 ? 1 : -1);
            shiftDelta[end + 1] -= (dir == 1 ? 1 : -1);
        }

        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += shiftDelta[i];
            cumulativeShift %= 26;
            int newChar = (s[i] - 'a' + cumulativeShift + 26) % 26;  
            s[i] = 'a' + newChar;
        }

        return s;
    }
};
