class Solution {
    public int maximumTastiness(int[] price, int k) {
        int n = price.length;
        int start =0, end = (int)1e9;
        int ans = price[n-1] - price[0];
        Arrays.sort(price);
        
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(predicate(mid,price,k))
            {
                ans = mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return ans;
    }
    public static boolean predicate(int x,int[] price, int k )
    {
        int prev = price[0];
        k--;
        for(int i=1; i<price.length; i++)
        {
            if(price[i]-prev >=x)
            {
                prev = price[i];
                k--;
            }
        }
        return k<=0;
    }
}