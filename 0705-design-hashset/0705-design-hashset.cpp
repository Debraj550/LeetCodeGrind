class MyHashSet {
public:
    vector<int> hashset;
    MyHashSet() {
        
    }
    
    void add(int key) {
        // if exists then leave if doesnt then add
        for(auto x: hashset) if(x == key) return;
        hashset.push_back(key);
    }
    
    void remove(int key) {
       // remove the key 
        auto it = find(hashset.begin(), hashset.end(), key);
        if(it != hashset.end()) hashset.erase(it);
        
    }
    
    bool contains(int key) {
        // check if it exists 
        auto it = find(hashset.begin(), hashset.end(), key);
        return it != hashset.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */