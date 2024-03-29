class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;           
        priority_queue<pair<int,char>> maxheap; 
        for(char c: s)
            freq[c]++;
        for(auto it: freq)
            maxheap.push({it.second,it.first}); 
        s="";   
        while(!maxheap.empty()){
            cout << maxheap.top().second << endl;
            s+=string(maxheap.top().first, maxheap.top().second);
            maxheap.pop();
        }
        return s;
    }
};