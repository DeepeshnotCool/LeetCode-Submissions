class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans;
        int l = 0, r = 0;
        for(; l < nums1.size() && r < nums2.size();){
            if(nums1[l] == nums2[r]){
                return nums1[l];
            } else if(nums1[l] < nums2[r]){
                l++;
            } else
                r++;
        }
        return -1;
        
    }
};