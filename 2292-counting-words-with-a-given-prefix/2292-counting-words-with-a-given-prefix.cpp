class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(auto word: words) {
            int startingIdx = word.find(pref);
            if(startingIdx == 0) res++;
        }
        return res;
    }
};