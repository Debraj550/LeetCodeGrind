class Solution {
public:
    bool canSortArray(vector<int>& values) {
        int n = values.size();
        for (int i = 0; i < n - 1; i++) {
            if (values[i] <= values[i + 1]) {
                continue;
            } else {
                if (__builtin_popcount(values[i]) ==
                    __builtin_popcount(values[i + 1])) {
                    swap(values[i], values[i + 1]); 
                } else {
                    return false; 
                }
            }
        }

        for (int i = n - 1; i >= 1; i--) {
            
            if (values[i] >= values[i - 1]) {
                continue;
            } else
                if (__builtin_popcount(values[i]) ==
                    __builtin_popcount(values[i - 1])) {
                    swap(values[i], values[i - 1]); 
                } else {
                    return false;  
                }
            }
        

        return true;
    }

};