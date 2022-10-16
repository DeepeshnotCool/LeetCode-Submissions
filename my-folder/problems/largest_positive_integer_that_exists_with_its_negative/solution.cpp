class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(temp + nums[j] == 0)
                    maxi = max(maxi, max(nums[j],temp));
            }
        }
        if(maxi == INT_MIN)
            return -1;
        return maxi;
    }
};