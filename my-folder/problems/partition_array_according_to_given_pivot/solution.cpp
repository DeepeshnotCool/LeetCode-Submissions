class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> right;
        vector<int> equal;
        vector<int> v;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < pivot)
            {
                left.push_back(nums[i]);
                continue;
            }
            if(nums[i] == pivot)
            {
                equal.push_back(nums[i]);
            }
            if(nums[i] > pivot)
            {
                right.push_back(nums[i]);
                continue;
            }
        }
        for(int i = 0; i < left.size(); i++)
        {
            v.push_back(left[i]);
        }
        for(int i = 0; i < equal.size(); i++)
        {
            v.push_back(equal[i]);
        }
        for(int i = 0; i < right.size(); i++)
        {
            v.push_back(right[i]);
        }
        return v;
        
    }
};