class StockSpanner {
public:
    stack<int> s;
    map<int, int> m;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty()){
            s.push(price);
            m[price] = 1;
            return m[price];
        } else {
            int count = 0;
            while(!s.empty() && price >= s.top()){
                count += m[s.top()];
                s.pop();
            }
            s.push(price);
            m[price] = count+1;
            return m[price];
        }
    }
};




/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */