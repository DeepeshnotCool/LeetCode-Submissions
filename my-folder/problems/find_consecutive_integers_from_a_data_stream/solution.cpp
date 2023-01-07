class DataStream {
public:
    
    map<int,int> m;
    queue<int> q;
    int tempVal, tempK;
    
    
    DataStream(int value, int k) {
        tempVal = value;
        tempK = k;
    }
    
    bool consec(int num) {
        q.push(num);
        m[num]++;
        if(q.size() < tempK)
            return false;
        if(q.size() == tempK){
            if(m.size() == 1 && m.find(tempVal) != m.end())
                return true;
            else
                return false;
        }
        auto front = q.front();
        q.pop();
        m[front]--;
        if(m[front] == 0)
            m.erase(front);
        if(m.size() == 1 && m.find(tempVal) != m.end())
                return true;
            else
                return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */