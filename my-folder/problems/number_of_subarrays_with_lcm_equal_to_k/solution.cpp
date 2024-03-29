class Solution {
public:
    
    long long gcd(long long int a, long long int b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
 
    long long lcm(int a, int b){
        return (a / gcd(a, b)) * b;
    }
 
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int l = nums[i];
            for(int j = i; j < nums.size(); j++){
                l = lcm(l, nums[j]);
                if(l == k)
                    ans++;
            }
        }
        return ans;
    }
};