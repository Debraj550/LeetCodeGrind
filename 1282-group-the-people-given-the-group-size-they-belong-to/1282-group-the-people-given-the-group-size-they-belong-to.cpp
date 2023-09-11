class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int> > mp;
        for(int i = 0; i < groupSizes.size(); i++) {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(auto it: mp) {
            int curr = 0;
            int targetSize = it.first;
            vector<int> temp;
            vector<int> people = it.second;
            
            for(int i = 0; i < people.size(); i++) {
                int p = people[i];
                if(p == -1)  
                    continue;
                temp.push_back(p);
                curr++;
                people[i] = -1;
                if(curr == targetSize) {
                    res.push_back(temp);
                    temp = {};
                    curr = 0;
                }
            }            
        }
        return res;
    }
};