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
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1)
        {
            if(nums[0] == target)
                return 0;
            return -1;
        }
        if(nums.size() == 2)
        {
            for(int i = 0; i < 2; i++)
                if(nums[i] == target)
                    return i;
            return -1;
        }
        int pivot = helper(nums);
        int l = 0;
        int r = nums.size()-1;
        while(l <= r)
        {
            if(nums[pivot] == target)
                return pivot;
            else if(nums[pivot] < target && target <= nums[r])
                l = pivot + 1;
            else
                r = pivot - 1;
            pivot = l + (r-l)/2;
        }
        return -1;
    }
};






