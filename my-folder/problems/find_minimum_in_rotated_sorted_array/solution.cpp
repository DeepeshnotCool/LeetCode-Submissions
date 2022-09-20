class Solution {
public:
     int helper(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size()-1;
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] >= nums[0])
            {
                l = mid+1;
            }
            else if(nums[mid] < nums[0])
            {
                r = mid;
            }
        }
        return l;
    }
    int findMin(vector<int>& nums) {
        if(nums[0] < nums[nums.size()-1])
        {
            return nums[0];
        }
        return nums[helper(nums)];
    }
};