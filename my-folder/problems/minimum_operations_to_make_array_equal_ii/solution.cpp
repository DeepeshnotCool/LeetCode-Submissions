class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        if(k==0){
            if(nums1 == nums2)
                return 0;
            return -1;
        }
        long long temp = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int diffX = nums1[i] - nums2[i];
            int diffY = nums2[i] - nums1[i];
            if(diffX == 0)
                continue;
            else if(diffX > 0 && diffX % k == 0){
                temp -= (1LL*(diffX/k));
                ans += (1LL*(diffX/k));
            }
            else if(diffX < 0 && diffY % k == 0){
                temp += (1LL*(diffY/k));
                ans += (1LL*(diffY/k));
            }
            else
                return -1;
        }
        if(temp == 0)
            return ans/2;
        return -1;
    }
};