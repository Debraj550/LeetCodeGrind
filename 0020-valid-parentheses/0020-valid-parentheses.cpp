class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto ch: s){
            if(ch == '(' || ch == '{' || ch == '[') 
                st.push(ch);
            else {
                if(!st.empty()) {
                    char top = st.top();
                    if(top == '(' && ch == ')' ) st.pop();
                    else if(top == '{' && ch == '}') st.pop();
                    else if(top == '[' && ch == ']') st.pop();
                    else return false;
                }   
                else st.push(ch);
            }
        }
        
        if(st.empty() == true) return true;
        return false;
    }
};

