class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        if(n < 3) return "";
        string ans = "";
        for(int i = 0; i < n-2; i++) {
            string x = num.substr(i,3);
            unordered_set<char> st;
            for(auto ch: x) st.insert(ch);
            if(st.size() != 1) continue;
            else {
                if(ans.size() == 0 || stoi(ans) < stoi(x)) 
                    ans = x;
            }
        }
        return ans;
    }
};