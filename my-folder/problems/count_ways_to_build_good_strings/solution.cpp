class Solution {
public:
    int mod=1e9+7;
    int dp[100001];
    int helper(int i, int zero, int one)
    {
        if(i == 0)
        return 1;
    
        if(dp[i] != -1)
            return dp[i];
        int ans = 0;
        if(i >= zero)
        ans=(ans + helper(i - zero, zero, one)) % mod;
        if(i >= one)
        ans = (ans + helper(i - one, zero, one)) % mod;
        dp[i] = ans;
        
        return dp[i] % mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        int count=0;
        memset(dp, -1, sizeof(dp));
        for(int i = low; i <= high; i++)
        {
            count = (count+helper(i, zero, one)) % mod;
        }
        return count;
    }
};

