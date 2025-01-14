class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);

        unordered_set<int> mpA, mpB;
        
        for(int i = 0; i < n; i++) {
            mpA.insert(A[i]);
            mpB.insert(B[i]);
            int commons = 0;
            for(int ele: mpA) {
                if(mpB.count(ele)) 
                    commons++;
            }
            res[i] = commons;
        }

        return res;
    }
};