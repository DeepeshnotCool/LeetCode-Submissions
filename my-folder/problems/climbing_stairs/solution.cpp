class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3)
            return n;
        vector<int> v(n+1,0);
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        v[3] = 3;
        for(int i = 4; i <= n; i++)
        {
            v[i] = v[i-1]+v[i-2]; 
        }
        return v[n];
    }
};