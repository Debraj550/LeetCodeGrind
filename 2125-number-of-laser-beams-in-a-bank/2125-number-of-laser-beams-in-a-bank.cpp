class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int start = -1;
        vector<int> temp;
        for(int i = 0; i < bank.size(); i++) {
            string x = bank[i];
            int count = 0;
            for(auto laser: x) {
                if(laser == '1') {
                    count++;
                }
            }
            if(count > 0) temp.push_back(count);
        }
        
        for(int i = 1; i < temp.size(); i++) {
            ans += temp[i] * temp[i-1];
        }
        return ans;
    }
};