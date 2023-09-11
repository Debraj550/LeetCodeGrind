class Solution {
public:
   
    int largestCombination(vector<int>& cand) {
        int maxi=0;
        //check iff the ith bit of each number is set, and find the total count of ith bit for each number
        //the highest count of set bits among all numbers is the answer as it ll generate a AND value of more than 0  -- debraj notes
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