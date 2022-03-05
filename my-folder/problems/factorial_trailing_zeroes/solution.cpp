class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5)
            return 0;
        int powFive = 5;
        int i = 2;
        int count = 0;
        while(powFive <= n)
        {
            count += n/powFive;
            powFive = pow(5,i);
            i++;
        }
        return count;
    }
};