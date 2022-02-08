class Solution {
public:
    int addDigits(int num) {
//         int temp = num;
//         while(num != 0)
//         {
//             int sum = 0;
//             while(temp != 0)
//             {
//                 sum += temp%10;
//                 temp /= 10;
//             }
//             if(sum/10 == 0)
//                 return sum;
//             temp = sum;
//             num/=10;
//         }
//         return 0;
        
        if(num == 0)
            return 0;
        if(num%9 == 0)
            return 9;
        return num%9;
        
    }
};


