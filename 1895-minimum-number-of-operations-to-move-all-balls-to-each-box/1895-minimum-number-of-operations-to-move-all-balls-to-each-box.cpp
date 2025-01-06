class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> oneIndex;
        for(int i = 0; i < n; i++) {
            char box = boxes[i];
            if(box == '1') oneIndex.push_back(i);
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(auto idx: oneIndex) {
                if(i != idx) {
                    cnt += abs(idx - i);
                }
            }
            res.push_back(cnt);
        }
        return res;

    }
};