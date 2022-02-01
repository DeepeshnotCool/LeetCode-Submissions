class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid = (l + (nums.size()-l))/2;
        //cout<<mid;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};