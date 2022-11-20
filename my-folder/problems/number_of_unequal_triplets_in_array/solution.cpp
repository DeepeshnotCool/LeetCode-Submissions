class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        for(int i = 0; i < n-2; i++)
        {
            for(int j = i+1; j < n-1; j++)
            {
                if(nums[j] != nums[i])
                {
                    for(int k = j+1; k < n; k++)
                    {
                        if(nums[k] != nums[j] && nums[k] != nums[i])
                            ans++;
                    }
                    
                }
            }
        }
        return ans;
    }
};