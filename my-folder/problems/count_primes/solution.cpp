class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n+1,true);
        isprime[0] = isprime[1] = false;
        for(long long i = 0; i <= n; i++)
        {
            if(isprime[i])
            {
                for(long long j = i*i; j <= n; j+=i)
                {
                    isprime[j] = false;
                }
            }
        }
        int count = 0;
        for(long long i = 2; i < n; i++)
        {
            if(isprime[i])
                count++;
        }
        return count;
        
    }
};