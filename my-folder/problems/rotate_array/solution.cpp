class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k)
            return;
        if(n < k)
            k = k%n;
        vector<int> v;
        for(int i = n-k; i < n; i++)
        {
            v.push_back(nums[i]);
            //nums.insert(nums.begin(), nums[n-1]);
            //nums.pop_back();
        }
        for(int i = 0; i < n-k; i++)
        {
            v.push_back(nums[i]);
        }
        nums = v;
    }
};