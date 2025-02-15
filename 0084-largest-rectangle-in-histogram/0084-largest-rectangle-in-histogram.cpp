class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {
            int currH = 0;
            if(i == n) currH = 0;
            else currH = heights[i];

            while(!st.empty() && heights[st.top()] > currH) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                res = max(res, h*w);
            }
            st.push(i);
        }

        return res;
    }
};