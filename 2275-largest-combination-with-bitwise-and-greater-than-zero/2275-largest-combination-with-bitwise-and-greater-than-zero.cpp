class Solution {
public:
   
    int largestCombination(vector<int>& cand) {
        int maxi=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(int x : cand) 
                if( x>>i & 1) 
                    c++;
            maxi = max(maxi,c);
        }
        return maxi;
    }
};