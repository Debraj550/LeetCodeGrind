class Solution {
public:
    string sortVowels(string s) {
        string t = s;
        unordered_map<char, bool> mp;
        string vowels = "aeiouAEIOU";
        for(auto c: vowels) mp[c] = true;
        string temp;
        for(auto ch: s) {
            //vowel
            if(mp[ch]) temp.push_back(ch);
        }
        sort(temp.begin(), temp.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(mp[ch] == true) {
                t[i] = temp[j++];
            }
            else t[i] = s[i];
        }
        
        return t;
    }
};