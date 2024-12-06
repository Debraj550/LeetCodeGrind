class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for(auto num: banned) st.insert(num);
        int currSum = 0;
        int noOfInt = 0;
        for(int i = 1; i <= n; i++) {
            if(currSum + i > maxSum) break;
            if(st.find(i) == st.end() && currSum + i <= maxSum) {
                currSum += i;
                noOfInt++;
            } 
            
        }
        return noOfInt;
    }
};