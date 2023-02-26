class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int l = 0, r = n/2;
        sort(nums.begin(), nums.end());
        
        while(l < n/2 && r < n){
            long long tempNum = 2 * 1LL * nums[l];
            if(tempNum <= nums[r]){
                ans += 2;
                l++;
                r++;
            } else
                r++;
        }
        return ans;
    }
};