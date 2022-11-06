class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        vector<int> v;
        int count = 0;
        for(auto it: nums){
            if(it != 0){
                v.push_back(it);
            } else{
                count++;
            }
        }
        while(count--){
            v.push_back(0);
        }
        return v;
    }
};