class Solution {
    public int smallestValue(int n) {
        int count =0;
        while(count !=1)
        {
            count =0;
            int ans = primeFactors(n,count);
            if(ans==n)
                return ans;
            n = ans;
            if(count==1)
                return ans;
        }
        return n;
    }
    public static int primeFactors(int n, int count)
    {
        int sum =0;
        while(n%2 ==0)
        {
            sum += 2;
            count++;
            n = n/2;
        }
        for(int i=3; i<=Math.sqrt(n); i = i+2)
        {
            while(n% i ==0)
            {
                count++;
                sum += i;
                n = n/i;
            }
        }
        if(n>2)
        {
            sum += n;
            count++;
        }
        return sum;
    }
}