class MyHashSet {
public:
    int bucket = 123;
    vector<vector<int>> hashset;
    MyHashSet() {
        hashset.resize(bucket);
    }
    
    void add(int key) {
        // if exists then leave if doesnt then add
        int idx = key % bucket;
        if(!contains(key))
            hashset[idx].push_back(key);
    }
    
    void remove(int key) {
       // remove the key 
        int idx = key % bucket;
        auto it = find(hashset[idx].begin(), hashset[idx].end(), key);
        if(it != hashset[idx].end())
            hashset[idx].erase(it);
        
    }
    
    bool contains(int key) {
        // check if it exists 
        int idx = key % bucket;
        auto it = find(hashset[idx].begin(), hashset[idx].end(), key);
        return it != hashset[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */