class Solution {
public:
    int helper(vector<int> &nums, int index, vector<int> &arr){
         if(index >= nums.size())
             return 0;
         if(nums.size() == 1)
             return nums[0];
         if(arr[index] != -1)
         {
             return arr[index];    
         }
         int a = nums[index] + helper(nums, index+2, arr);
         int b = helper(nums, index+1, arr);
         arr[index] = max(a, b);
         return arr[index];
     }
    int rob(vector<int>& nums) {
        int index = 0;
        int size = nums.size(); 
        vector<int> arr(size+1, -1);
        return helper(nums, index, arr);        
    }
};