class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums){
            sum += it;
        }
        int digit = 0;
        for(auto it: nums){
            while(it!= 0){
                digit += it % 10;
                it /= 10;
            }
        }
        return abs(sum-digit);
    }
};