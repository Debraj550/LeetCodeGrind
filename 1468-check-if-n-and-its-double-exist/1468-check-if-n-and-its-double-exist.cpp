class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i =0; i < arr.size(); i++) {
            mp[2*arr[i]] = i;
        }

        for(int i = 0; i < arr.size(); i++) {
            if(mp.find(arr[i]) != mp.end() && i != mp[arr[i]])
                return true;
        }
        return false;
    }
};