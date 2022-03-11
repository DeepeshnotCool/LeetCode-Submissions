class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        do
        {
            s.insert(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        vector<vector<int>> v;
        for(auto it: s)
        {
            v.push_back(it);
        }
        return v;
    }
};