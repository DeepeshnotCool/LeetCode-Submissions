class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_map<double, int> m;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        while(i < j)
        {
            double x = (nums[i] + nums[j])/2.0;
            m[x]++;
            i++;
            j--;
        }
        return m.size();
        
    }
};