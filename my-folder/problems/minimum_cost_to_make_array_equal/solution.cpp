class Solution {
public:
    

     long long solve(vector<int>& nums, vector<int>& cost,int mid)
    {
        long long temp=0;
        for(int i=0;i<nums.size();i++)
        {
            int diff=abs(mid-nums[i]);
            temp+=(1LL*cost[i]*diff);
        }
        return temp;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int start=*min_element(nums.begin(),nums.end());
        int end=*max_element(nums.begin(),nums.end());
        
        int mid;
        long long ans=0;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            long long temp1=0,temp2=0,temp3=0;
            temp1=solve(nums,cost,mid);
            temp2=solve(nums,cost,mid+1);
            temp3=solve(nums,cost,mid-1);
            if(temp1<=temp2&&temp1<=temp3)
                return temp1;
            else if(temp1<=temp2&&temp3<=temp1)
                end=mid-1;
            else
                start=mid+1;
           
        }
        return 0;
    }
};