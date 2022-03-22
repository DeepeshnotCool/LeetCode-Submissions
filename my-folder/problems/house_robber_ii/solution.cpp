class Solution {
public:
    int helper(vector<int> &nums, int index, vector<int> &arr, int first){
         if(index >= nums.size())
             return 0;
         if(nums.size() == 1)
              return nums[0];
         if(index == nums.size() - 1 && first == 0)
             return 0;
         if(arr[index] != -1)
         {
             return arr[index];    
         }
         // if(nums.size()%2 != 0){
         //     if(index == nums.size()-1)
         //     {
         //         return 0;
         //     }
         // }
         int a = nums[index] + helper(nums, index+2, arr, first);
         int b = helper(nums, index+1, arr, first);
         arr[index] = max(a, b);
         return arr[index];
     }
    int rob(vector<int>& nums) {
        int index = 0;
        int size = nums.size(); 
        vector<int> arr(size + 1, -1);
        int ans1 = helper(nums, index, arr, 0);
        vector<int> arr1(size + 1, -1);
        int ans = max(ans1 , helper(nums, index + 1, arr1, 1));
        cout<<ans1<<ans;
        return ans;
    }
};