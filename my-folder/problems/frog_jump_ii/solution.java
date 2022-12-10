class Solution {
    public int maxJump(int[] stones) {
        int n = stones.length;
        int ans =0;
        if(n==2)
            return stones[1]- stones[0];
        if(n%2==0)
        {
            for(int i=2; i<n-1; i+=2)
            {
                int x = stones[i]- stones[i-2];
                ans = Math.max(ans,x);
            }
            ans = Math.max(ans, stones[n-1] - stones[n-2]);
            for(int i= n-3; i>=0; i-=2)
            {
                int x = stones[i+2]- stones[i];
                ans = Math.max(ans,x);
            }
            return ans;
        }
            for(int i=2;i<n;i+=2)
            {
            int x=stones[i]-stones[i-2];
                ans=Math.max(ans,x);
                
            }
            for(int i=n-4;i>=1;i-=2)
            {
                int x=stones[i+2]-stones[i];
                ans=Math.max(ans,x);
                
            }
            return ans;
    }
}