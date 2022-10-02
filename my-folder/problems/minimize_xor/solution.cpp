class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set_num1 = __builtin_popcount(num1);
        int set_num2 = __builtin_popcount(num2);
        int ans = 0;
        for(int i = 0; i <= 31; i++){
            int mask = 1 << i;
            int set = num1 & mask;
            if(set == 0 && set_num2 > set_num1){
                ans |= (mask);
                set_num2--;
            }
            else if(set && set_num1 > set_num2) 
                set_num1--;
            else 
                ans |= set;
        }
        return ans;
    }
};