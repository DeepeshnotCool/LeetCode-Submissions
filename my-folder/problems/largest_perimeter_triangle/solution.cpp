class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int first = 0, second = 0, third = 0;
        for(int i = 0, j = 1, k = 2; i < n-2, j < n-1, k < n; i++, j++, k++)
        {
            first = nums[i];
            second = nums[j];
            third = nums[k];
            if(second + third > first)
                return first + second + third;
        }
        return 0;
    }
};