class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int count = 0;
        for(auto num: nums) if(num == k) count++;

        int ans = count;

        for(int i = 1; i <= 50; i++) {
            if(i == k) continue;
            int maxi = 0;
            int s = 0;
            for(auto num: nums) {
                if(num == i) s++;
                else if(num == k) s--;
                
                if(s < 0) s = 0;
                maxi = max(maxi, s);
                ans = max(ans, count + maxi);
            }
        }
        return ans;



        return ans;

        
    }
};