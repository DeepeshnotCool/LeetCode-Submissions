class Solution {
public:
    int arrangeCoins(int n) {
        /*
        vector<int> v(n+1, 0);
        int value = 1;
        int count = 2;
        int k = 1;
        bool flag = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < count; j++)
            {
                if(k > n)
                {
                    flag = false;
                    break;
                }
                v[k] = value;
                k++;
            }
            if(!flag)
                break;
            cout<<k;
            value++;
            count++;
        }
        return v[n];
        */
        int count = 0;
        int i = 1;
        while(1)
        {
            if(i <= n)
            {
                n -= i;
                count++;
            }
            else
                break;
            i++;
        }
        return count;
        
        
        
    }
};