class Solution {
   // static int [] dp ;
    public int rob(int[] nums) {
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

    // public int f(int ind, int[]nums, int[] dp)
    // {
    //     if(ind==0)
    //       return nums[0];
    //     if(ind<0)
    //       return 0;
    //     if(dp[ind] != -1)
    //       return dp[ind];

    //     int take = nums[ind] + f(ind-2, nums, dp);
    //     int nontake = 0 + f(ind-1, nums, dp);

    //     return dp[ind] = Math.max(take, nontake); 
    // }
}