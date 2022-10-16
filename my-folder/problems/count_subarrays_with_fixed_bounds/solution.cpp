class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        long long deselect = -1; 
        long long mini = -1; 
        long long maxi = -1;
        for (int i = 0; i < nums.size(); ++i) {
            
            if (nums[i] < minK || nums[i] > maxK)
                deselect = i;
            
            if (nums[i] == minK) 
                mini = i;
            
            if (nums[i] == maxK) 
                maxi = i;
            
            ans += max(0LL, min(mini, maxi) - deselect);
            
            //cout<<deselect<<" "<<mini<<" "<<maxi<<" "<<ans<<endl;
        }
        return ans; 
    }
};