class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int sum = 0;
        int x = 0;
        // m[0] = 1;
        if(nums.size() < 2)
            return false;
        for(auto it: nums){
            sum += it;
            sum %= k;
            if(m[sum]){
                return true;
            }
            cout<<sum<<endl;
            m[x] = 1;
            x = sum;
        }
        return false;
    }
};