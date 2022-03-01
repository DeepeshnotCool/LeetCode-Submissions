class Solution {
public:
    bool isHappy(int n) {
        if(n == 1)
            return true;
        map<int, int> m;
        m[n]++;
        while(true)
        {
            int temp = 0;
            while(n != 0)
            {
                temp += pow(n%10,2);
                n /= 10;
            }
            m[temp]++;
            if(m[temp] > 1)
            {
                return false;
            }
            if(temp == 1)
                return true;
            n = temp;
        }
    }
};





