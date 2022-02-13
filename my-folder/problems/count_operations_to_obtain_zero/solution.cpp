class Solution {
public:
    int countOperations(long long num1, long long num2) {
        int count = 0;
        while(num1 && num2)
        {
            if(num1 <= num2)
                num2 = num2-num1;
            else
                num1 = num1 - num2;
            count++;
        }
        return count;
    }
};