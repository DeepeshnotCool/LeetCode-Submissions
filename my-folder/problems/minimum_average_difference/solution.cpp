class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n+2,0);
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+nums[i];
        }
        pre[n+1]=pre[n];
        int mini=INT_MAX;
        int ans=-1;
        for(int i=1;i<n;i++)
        {
            double x=pre[i]/i;
            double y=(pre[n+1]-pre[i])/(n-i)*(1.0);
            int tx=round(x);
            int ty=round(y);
            if(abs(tx-ty)<mini)
            {
                mini=abs(tx-ty);
                ans=i-1;
            }

        }
        double temp=pre[n]/n*1.0;
          int r=round(temp);
          if(r<mini)
          return n-1;
        return ans;
    }
};