class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int, bool> m;
        for(int i = 0; i < nums.size()-1; i++){
            int sum = 0;
            sum = nums[i] + nums[i+1];
            if(m[sum]){
                return true;
            }
            m[sum] = true;
        }
        return false;
    }
};