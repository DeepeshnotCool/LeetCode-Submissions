class Solution {
public:

    int helper(int n, vector<int>& memo){
        if(n == 0)
            return memo[0] = 0;
        if(memo[n] != -1)
            return memo[n];
        int mini = INT_MAX;
        for(int i = 1; i <= sqrt(n); i++){
            int val = 1 + helper(n - (i*i), memo);
            mini = min(mini, val);
        }
        return memo[n] = mini;
    }


    int numSquares(int n) {
        vector<int> memo(n+1, -1);
        return helper(n, memo);
    }
};

