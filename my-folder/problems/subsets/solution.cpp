class Solution {
public:
    
    void helper(vector<int>& nums, vector<vector<int>>& v, int index, int n, vector<int>& temp)
    {
        if(index == n)
        {
            v.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(nums,v,index+1,n,temp);
        temp.pop_back();
        helper(nums,v,index+1,n,temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> temp;
        helper(nums,v,0,nums.size(),temp);
        return v;
    }
};