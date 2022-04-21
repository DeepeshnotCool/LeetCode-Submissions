class MyHashSet {
    vector<int> v;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        v.push_back(key);
    }
    
    void remove(int key) {
        vector<int> temp;
        for(auto it : v){
            if(it != key){
                temp.push_back(it);
            }
        }
        v = temp;
    }
    
    bool contains(int key) {
        for(auto it: v){
            if(it == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */



