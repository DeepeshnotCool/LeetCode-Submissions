class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it : stones){
            pq.push(it);
        }
        while(pq.size() != 1){
            if(pq.empty())
                return 0;
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            if(top1 != top2)
                pq.push(abs(top1 - top2));
        }
        if(pq.empty())
            return 0;
        return pq.top();
        
        
        
    }
};