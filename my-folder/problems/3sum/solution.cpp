class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> v;
        set<vector<int>> s;
        for(int i = 0; i < n; i++)
        {
            int l = i+1;
            int r = n-1;
            int x = nums[i];
            while(l<r)
            {
                if(x+nums[l]+nums[r] == 0)
                {
                    vector<int> temp = {x,nums[l],nums[r]};
                    s.insert(temp);
                    l++;
                    r--;
                }
                else if(x+nums[l]+nums[r] < 0)
                {
                    l++;
                }
                else
                    r--;
            }
        }
        for(auto x: s)
        {
            v.push_back(x);
        }
        return v;
    }
};