class Solution {
public:
    
    int helper(int i, int j, int n, vector<int>& memo){
        if(i >= j)
            return 1;
        if(memo[j-1+1] != -1)
            return memo[j-i+1];
        int ans = 0;
        for(int k = i; k <= j; k++){
            ans += helper(i , k-1, n, memo) * helper(k+1, j, n, memo);
        }
        return memo[j-i+1] = ans;
    }

    int numTrees(int n) {
        vector<int> memo(n+1, -1);
        return helper(0, n-1, n, memo);
    }
};

