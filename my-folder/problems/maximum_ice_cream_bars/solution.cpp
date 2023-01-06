class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0, count = 0;
        for(auto it: costs){
            sum += it;
            if(sum > coins)
                break;
            count++;
        }
        return count;
    }
};