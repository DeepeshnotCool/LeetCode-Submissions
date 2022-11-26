class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum = 0, result = 0;
        m[sum] = 1;
        for (auto it : nums) {
            sum += it;
            result += m[sum - k];
            m[sum]++;
        }
        return result;
    }
};