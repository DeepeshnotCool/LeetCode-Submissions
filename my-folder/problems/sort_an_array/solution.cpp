class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        return v;
    }
};