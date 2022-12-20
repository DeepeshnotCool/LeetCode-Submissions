class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==1)
           return nums[0];
        int[] temp1 = new int[n-1];
        int[] temp2 = new int[n-1];

        for(int i=0; i<n; i++)
        {
            if(i !=0)
               temp2[i-1] = nums[i];
            if(i != n-1)
              temp1[i] = nums[i];   
        }
        return Math.max(f(temp1),f(temp2));
    }
    public int f(int[] nums) {
      int n = nums.length;
     // int[] dp = new int[n];
    // dp[0] =nums[0];
    int prev = nums[0];
    int prev2 = 0;

     for(int i=1; i<n; i++)
     {
         int take = nums[i];
         if(i >1)
           take += prev2;
         int nontake = 0 + prev;
         int curr = Math.max(take,nontake);  

         prev2 = prev;
         prev = curr;
     }
     return prev;
    }
}