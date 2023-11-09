class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto c: s) {
            if(c == ']') {
                if(!st.empty() && st.top() == '[') 
                    st.pop();
                else st.push(c);
            }
            else st.push(c);
        }
        int closing = st.size()/2;
        int ans = (closing + 1)/2;
        return ans;
    }
};