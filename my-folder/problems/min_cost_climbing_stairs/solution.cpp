class Solution {
public:
    
    int helper(vector<int> &cost, int s, vector<int> &memo){
        if(s >= cost.size())
            return 0;
        if(s == cost.size()-1)
            return cost[s];
        if(memo[s] != -1)
            return memo[s];
        int a = helper(cost, s+1, memo);
        int b = helper(cost, s+2, memo);
        return memo[s] = cost[s] + min(a,b);
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size()+1, -1);
        int a = helper(cost, 0, memo);
        int b = helper(cost, 1, memo);
        return min(a,b);
    }
};