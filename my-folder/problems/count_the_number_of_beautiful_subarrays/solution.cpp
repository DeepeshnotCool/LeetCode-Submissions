class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        map<int, int> m;
        long long ans = 0;
        int temp = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            temp ^= nums[i];
            if(temp == 0) {
                count++;
                continue;
            }
            if(m.find(temp) != m.end()) {
                ans += m[temp];
            }
            m[temp]++;
        }
        ans += (count * 1LL * (count + 1))/2;
        return ans;
    }
};