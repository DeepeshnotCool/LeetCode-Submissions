class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        int m = queries.length;
        int n = nums.length;
        int[] ans = new int[m];
        Arrays.sort(nums);
        for(int i=0; i<m;i++)
        {
            int sum =0, ct=0;
            
            for(int j=0;j<n;j++)
            {
                if(sum+nums[j]<=queries[i])
                {
                    sum +=nums[j];
                    ct++;
                }
            }
            ans[i] =ct;
        }
        System.out.println(Arrays.toString(ans));
        return ans;
    }
}