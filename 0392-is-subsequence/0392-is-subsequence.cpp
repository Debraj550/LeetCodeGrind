class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        int i = 0;
        int j = 0;
        
        while(i < t.size()) {
            if(t[i] == s[j]) 
                j++;
            i++;
        }
        
        return j == s.size();
    }
};