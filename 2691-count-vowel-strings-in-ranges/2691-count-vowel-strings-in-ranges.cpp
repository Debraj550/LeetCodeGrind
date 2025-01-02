class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixVowelCount(words.size() + 1, 0);

        for(int i = 0; i < words.size(); i++) {
            string currWord = words[i];
            if(isVowel(currWord[0]) && isVowel(currWord[currWord.size()-1]))
                prefixVowelCount[i+1] = 1 + prefixVowelCount[i];
            else
                prefixVowelCount[i+1] = prefixVowelCount[i];
        }
        vector<int> res;
        for(auto query: queries) {
            int l = query[0];
            int r = query[1];
            int noOfVowelStrings = prefixVowelCount[r+1] - prefixVowelCount[l];
            res.push_back(noOfVowelStrings);
        }
        return res;
    }
};