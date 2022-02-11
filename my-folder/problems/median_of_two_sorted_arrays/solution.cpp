class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int> v;
        int m = nums1.size();
        int n = nums2.size();
        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m)
        {
            v.push_back(nums1[i]);
            i++;
        }
        while(j < n)
        {
            v.push_back(nums2[j]);
            j++;
        }
        double ans;
        if(v.size()%2 == 0)
        {
            ans = (v[v.size()/2] + v[v.size()/2-1])/(2.0);
            return ans;
        }
        ans = v[v.size()/2];
        return ans;
        
    }
};