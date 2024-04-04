class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        int counter=0;
        int x;
        for(int i=0;i<=n;i++){
            counter=0;
            x=i;
            while(x){
                counter+=1;
                x=x&(x-1);
            }
            v.push_back(counter);
        }
        return v;
    }
};