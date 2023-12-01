class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x, y;
        for(auto s: word1) x += s;
        for(auto s: word2) y += s;
        return x == y;
    }
};