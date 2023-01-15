class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        map<long long, long long> m;
        long long ans = 0, i = 0, j = 0, count = 0;
        while(j < n){
            m[nums[j]]++;
            long long x = m[nums[j]];
            if(x >= 2){
                long long red = ((x - 1) * (x - 2))/2;
                count -= red;
                count += (x * (x - 1))/2;   
            }
            if(count >= k){
                ans += (n - j);
                while(count >= k){
                    long long x = m[nums[i]];
                    m[nums[i]]--;
                    i++;
                    long long red = (x * (x - 1))/2;
                    count -= red;
                    count += ((x-1)*(x-2))/2;
                    ans += (n-j);
                }
                ans -= (n-j);
            }
            j++;
        }
        return ans;
    }
};