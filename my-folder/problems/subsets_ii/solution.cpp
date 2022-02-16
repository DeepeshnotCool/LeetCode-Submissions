class Solution {
public:
    void helper(vector<int>& nums, int index, vector<vector<int>>& v, vector<int>& temp, int n)
    {
        if(index == n)
        {
            //sort(temp.begin(),temp.end());
            v.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(nums,index+1,v,temp,n);
        temp.pop_back();
        helper(nums,index+1,v,temp,n);
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> sv;
        vector<int> temp;
        int n = nums.size();
        vector<vector<int>> v;
        helper(nums,0,v,temp,n);
        for(auto it : v)
        {
            sort(it.begin(),it.end());
            sv.insert(it);
        }
        vector<vector<int>> ans;
        for(auto it:sv)
            ans.push_back(it);
        return ans;
    }
};