class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int b = 0, e = 0;
        int n = s.size();
        unordered_set<char> st;
        
        int res = 0;
        while(e < n) {
            char ch = s[e];
            //not present in map
            if(st.find(ch) == st.end()) {
                st.insert(ch);
                res = max(res, e - b + 1);
                e++;
            }
            //if the character is present
            else {
                st.erase(s[b]);
                b++;
            }
        }
        
        return res;
    }
};