class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int temp = num;
        while (num != 0) {
            int digit = num % 10;
            if (digit != 0 && temp % digit == 0) {
              count++;
            }
            //cout<<digit<<" "<<num<<" "<<count<<endl;
            num /= 10;
            
        }
        return count;
    }
};


