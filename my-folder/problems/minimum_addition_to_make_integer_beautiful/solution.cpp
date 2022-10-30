class Solution {
public:
    
    long long getSum(long long n)
    {
        long long sum;
        for (sum = 0; n > 0; sum += n % 10, n /= 10);
        return sum;
    }
    
    
    long long round(long long n, long long size)
    {
        long long a = (n / size) * size;
        long long b = a + size;
        return b;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        if(getSum(n) <= target)
            return 0;
        string s = to_string(n);
        for(int i = 1; i <= s.size(); i++){
            long long size = pow(10,(i));
            long long val = round(n, size);
            if(getSum(val) <= target){
                return val - n;
            }
        }
        return 0;
    }
};