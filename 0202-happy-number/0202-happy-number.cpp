class Solution {
public:
    int findSum(int n) {
        if(n == 0) return 0;
        return (n%10)*(n%10) + findSum(n/10); 
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1) {
            int x = findSum(n);
            if(st.find(x) != st.end()) return false;
            st.insert(x);
            n = x;
        }
        return true;
    }
};