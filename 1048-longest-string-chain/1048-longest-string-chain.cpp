class Solution {
public:

    
    int longestStrChain( vector<string>& words) {
        sort(words.begin(), words.end(), [] (const string a, const string b) {
            return a.size() < b.size();
        });
        
        unordered_map<string, int> dp;
    
        
        int res = 1;
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            int currLen = 1;
            
            for(int j = 0; j < word.size(); j++) {
                string temp = word.substr(0,j) + word.substr(j+1, word.size() + 1);
                //the word except the current element of this word is present then
                if(dp.find(temp) != dp.end()) {
                    int prevLen = dp[temp];
                    currLen = max(currLen, prevLen + 1);
                }
            }
            dp[word] = currLen;
            res = max(res, currLen);
        }
        return res;
    } 
};