class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto it: piles){
            pq.push(it);
        }
        while(k--){
            int top = pq.top();
            //cout<<top<<" ";
            top = top - (top/2);
            pq.pop();
            pq.push(top);
            //cout<<top<<" ";
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};