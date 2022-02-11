class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        if(nums.size() == 0)
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;   
        }
        vector<int>::iterator lower, upper;
        lower = lower_bound(nums.begin(), nums.end(), target);
        upper = upper_bound(nums.begin(), nums.end(), target);
        int l = 0;
        int r = nums.size()-1;
        bool flag = true;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid] == target)
            {
                flag = false;
                break;
            }
            if(nums[mid] < target)
            {
                l = mid+1;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
        }
        if(flag)
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;  
        }
        v.push_back(lower-nums.begin());
        v.push_back(upper-nums.begin()-1);
        return v;
    }
};