class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size()/3;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        vector<int> v;
        for(auto it: m)
        {
            if(it.second > n)
                v.push_back(it.first);
        }
        return v;
    }
};