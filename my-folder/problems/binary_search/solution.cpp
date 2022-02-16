class Solution {
public:
    
    int bSearch(vector<int>& nums, int target, int l, int r)
    {
        if(l > r)
            return -1;
        int mid = l + (r-l)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        if(nums[mid] > target)
        {
            return bSearch(nums,target,l,mid-1);
        }
        return bSearch(nums,target,mid + 1, r);
    }
    
    
    int search(vector<int>& nums, int target) {
//         int l = 0;
//         int r = nums.size()-1;
//         int mid = (l + (nums.size()-l))/2;
//         //cout<<mid;
//         while(l <= r)
//         {
//             int mid = (l + r)/2;
//             if(nums[mid] == target)
//                 return mid;
//             if(nums[mid] < target)
//             {
//                 l = mid + 1;
//             }
//             else if(nums[mid] > target)
//             {
//                 r = mid - 1;
//             }
//         }
//         return -1;
        
        return bSearch(nums, target,0,nums.size()-1);
        
    }
};