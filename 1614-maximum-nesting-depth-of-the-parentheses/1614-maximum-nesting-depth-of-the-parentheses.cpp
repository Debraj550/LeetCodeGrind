class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int res = 0;
        for(auto c: s) {
            if(c == '(') {
                depth++;
                res = max(depth, res);
            }
            else if(c == ')') depth--;
        } 
        return res;
    }
};