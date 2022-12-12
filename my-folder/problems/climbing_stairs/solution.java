class Solution {
//     public int climbStairs(int n) {
//         if(n==0) return 1;
//         if(n==1) return 1;
        
//         int left = climbStairs(n-1);
//         int right = climbStairs(n-2);
        
//         return left+right;
//     }
    public int climbStairs(int n) {
    int a = 1, b = 1;
    while (n-- > 0)
        a = (b += a) - a;
    return a;
}

}