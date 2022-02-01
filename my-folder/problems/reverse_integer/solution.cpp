class Solution {
public:
    int reverse(int x) {
        bool flag = true;
        if(x == -2147483648 || x == 2147483647)
            return 0;
        if(x < 0)
        {
            flag = false;
            x *= -1;
        }
        //int size = floor(log10(x)+1);
        string s = to_string(x);
        int size = s.size();
        //cout<<size;
        long long num = 0;
        while(x != 0)
        {
            if(num < (pow(2,31)*-1) || num > (pow(2,31)-1))
                return 0;
            num += (x%10)*pow(10,size-1);
            x = x/10;
            size--;
        }
        if(!flag)
            num *= -1;
        return num;
            
    }
};