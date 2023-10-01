class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while(j < s.size()) {
            //skip whihte spaces in beginning
            while(j < s.size() && s[j] == ' ') j++;
            i = j;
            
            //skip characters in middle
            while(j < s.size() && (s[j] != ' ' && j != s.size()) )
                j++;
            
            //reverse
            int start = i, end = j-1;
            while(start < end) {
                swap(s[start++], s[end--]);
            }
            
            j++;
            i = j;
        }
        
        return s;
    }
};