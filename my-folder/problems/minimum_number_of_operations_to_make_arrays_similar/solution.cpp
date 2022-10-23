class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> v1, v2, v3, v4;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]&1)
                v2.push_back(nums[i]);
            else
                v1.push_back(nums[i]);
            
            if(target[i]&1)
                v4.push_back(target[i]);
            else
                v3.push_back(target[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());
        sort(v4.begin(),v4.end());
        int n1=v2.size();
        for(int i=0;i<n1;i++)
        {
            if(v2[i]<v4[i])
            {
                int diff=v4[i]-v2[i];
                ans+=(diff/2);
            }
            else if(v2[i]==v4[i])
            {
                continue;
            }
            
        }
         for(int i=0;i<v1.size();i++)
        {
            if(v1[i]<v3[i])
            {
                int diff=v3[i]-v1[i];
                ans+=(diff/2);
            }
            else if(v1[i]==v3[i])
            {
                continue;
            }
            
        }
        return ans;
        
    }
};