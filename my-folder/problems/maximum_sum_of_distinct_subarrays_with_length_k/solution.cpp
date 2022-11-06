class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n)
            return 0;
        long long maxi = 0, sum = 0;
        map<int, int> m;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
            sum += nums[i];
            
            if (i >= k){
                m[nums[i - k]] -= 1;
                sum -= nums[i - k];

                if (m[nums[i - k]] == 0)
                    m.erase(nums[i - k]);
            }
            if(m.size() == k)
                maxi = max(maxi, sum);
        }
        return maxi;
    }
};