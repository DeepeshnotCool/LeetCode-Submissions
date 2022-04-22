class MyHashMap {
public:
    vector<pair<int,int>> v;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == key){
                v[i].second = value;
                return;
            }
        }
        v.push_back({key,value});
    }
    
    int get(int key) {
        for(auto it : v){
            if(it.first == key)
                return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        vector<pair<int, int>> temp;
        for(auto it: v){
            if(it.first != key)
                temp.push_back({it.first, it.second});
        }
        v = temp;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */