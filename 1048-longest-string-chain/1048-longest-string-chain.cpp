
class Solution {
    
private:

    int dfs(unordered_set<string> &words, unordered_map<string, int> &memo, string currentWord) {
        if (memo.find(currentWord) != memo.end()) {
            return memo[currentWord];
        }
        int maxLength = 1;
        for (int i = 0; i < currentWord.length(); i++) {
            string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
            if (words.find(newWord) != words.end()) {
                int currentLength = 1 + dfs(words, memo, newWord);
                maxLength = max(maxLength, currentLength);
            }
        }
        memo[currentWord] = maxLength;

        return maxLength;
    }

public :
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> memo;
        unordered_set<string> wordsPresent;
        for (const string &word : words) {
            wordsPresent.insert(word);
        }
        int ans = 0;
        for (const string &word : words) {
            ans = max(ans, dfs(wordsPresent, memo, word));
        }
        return ans;
    }
};
