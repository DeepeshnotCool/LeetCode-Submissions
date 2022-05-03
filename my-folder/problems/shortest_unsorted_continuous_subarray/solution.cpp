class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int l = 0;
        int r = nums.size() - 1;
        while(l < nums.size() && nums[l] == temp[l])
            l++;
        while(r >= 0 && nums[r] == temp[r])
            r--;
        return ((r - l) < 0) ? 0 : (r - l + 1);
    }
};