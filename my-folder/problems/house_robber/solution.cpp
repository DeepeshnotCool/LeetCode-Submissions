class Solution {
public:
    /*
    int helper(vector<int> &nums, int index, vector<int> &arr){
        //cout<<index<<endl;
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
         cout<<index<<"-"<<max(a,b)<<" "<<a<<","<<b<<endl;
         arr[index] = max(a, b);
        
         return arr[index];
     }
    int rob(vector<int>& nums) {
        int index = 0;
        int size = nums.size(); 
        vector<int> arr(size+1, -1);
        return helper(nums, index, arr);        
    }
    */
    
    int rob(vector<int>& nums) {
        if(nums.size() < 2){
            return nums[0];
        }
        vector<int> arr(nums.size()+1, 0);
        arr[nums.size()-1] = nums[nums.size()-1];
        arr[nums.size()-2] = max(nums[nums.size()-2], nums[nums.size()-1]);
        for(int i = nums.size()-3; i >= 0; i--){
            arr[i] = max(arr[i+1], nums[i] + arr[i+2]);
        }
        return arr[0];
        
        
        
    }
    
    
    
    
    
    
};