class Solution {
public:
    string type(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                if(!st.empty()) st.pop();
            }
            else st.push(s[i]);
        }
        string temp = "";
        while(!st.empty()) {
            temp += st.top();
            st.pop();
        }
        return temp;
    }
    bool backspaceCompare(string s, string t) {
        string s1 = type(s);
        string s2 = type(t);
        return s1 == s2;
    }
};