class Solution {
private:
    long long helper(long long op1, long long op2, string op) {
        if(op == "+") return op2+op1;
        if(op == "-") return op2-op1;
        if(op == "*") return op2*op1;
        if(op == "/") return op2/op1;
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(auto token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                long long op1,op2;
                if(!st.empty()){
                    op1 = st.top(); 
                    st.pop();
                }
                if(!st.empty()) {
                    op2 = st.top();
                    st.pop();
                }
                long long evalNum = helper(op1,op2,token);
                st.push(evalNum);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};