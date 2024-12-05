class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char,int>> sQ, tQ;
        for(int i = 0; i < start.size(); i++) {
            if(start[i] != '_') sQ.push({start[i], i});
            if(target[i] != '_') tQ.push({target[i], i});
        }

        if(sQ.size() != tQ.size()) return false;

        while(!sQ.empty()) {
            auto [startVal, startIdx] = sQ.front();
            auto [targetVal, targetIdx] = tQ.front();
            sQ.pop();
            tQ.pop();
            if(startVal != targetVal || startVal == 'L' && startIdx < targetIdx || startVal == 'R' && startIdx > targetIdx)
                return false;
        }
        return true;
    }
};