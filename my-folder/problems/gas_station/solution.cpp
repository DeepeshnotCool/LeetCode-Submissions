class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0, costSum = 0;
        for(int i = 0; i < gas.size(); i++){
            gasSum += gas[i];
            costSum += cost[i];
        }

        if(gasSum < costSum)
            return -1;
        int index = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); i++){
            sum += gas[i]-cost[i];
            if(sum < 0){
                index = i+1;
                sum = 0;
            }
        }
        return index;
    }
};