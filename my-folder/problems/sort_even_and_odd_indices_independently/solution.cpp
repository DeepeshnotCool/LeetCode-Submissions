class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd,even;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i%2 == 0)
            {
                even.push_back(nums[i]);
            }
            else
            {
                odd.push_back(nums[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int> ());
        vector<int> ans(nums.size(),0);
        int j = 0, k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i%2 == 0)
            {
                ans[i] = even[j];
                j++;
            }
            else
            {
                ans[i] = odd[k];
                k++;
            }
        }
        return ans;
    }
};