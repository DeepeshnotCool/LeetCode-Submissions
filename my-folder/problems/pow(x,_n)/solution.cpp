class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n > 0)
        {
            if(n % 2 == 0)
            {
                double ans = myPow(x, n/2);
                return ans*ans;
            }
            else 
            {
                double ans = myPow(x, n/2);
                return x*ans*ans;
            }
        }
        else
        {
            if(n % 2 == 0)
            {
                double ans = myPow(x, n/2);
                return ans*ans;
            }
            else 
            {
                double ans = myPow(x, n/2);
                return (1/x)*ans*ans;
            }
        }
    }
};