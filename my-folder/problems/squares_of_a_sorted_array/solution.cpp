class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] = (nums[i]*nums[i]);
        }
        sort(nums.begin(), nums.end());
        return nums;
        */
        int l = 0;
        int r = nums.size()-1;
        vector<int> v(nums.size(),0);
        int k = nums.size()-1;
        while(l <= r)
        {
            if(abs(nums[l]) <= abs(nums[r]))
            {
                v[k] = abs(nums[r]);
                r--;
                k--;
            }
            else
            {
                v[k] = abs(nums[l]);
                l++;
                k--;
            }
        }
        for(int i = 0; i < v.size(); i++)
        {
            v[i] = (v[i]*v[i]);
        }
        return v;
        
    }
};