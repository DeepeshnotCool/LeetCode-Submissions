class Solution {
public:

    // int helper(vector<int> &nums, int start, int n, vector<int> &memo){
    //     if(start == n){
    //         return 0;
    //     }

    //     if(memo[start] != -1)
    //         return memo[start];

    //     int mini = INT_MAX-1;

    //     for(int i = 1; i <= nums[start]; i++){
    //         if(start + i > n)
    //             continue;
    //         int ans = 1 + helper(nums, start + i, n, memo);
    //         mini = min(mini, ans);
    //     }

    //     return memo[start] = mini;
    // }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n+1, -1);
        memo[n-1] = 0;
        for(int start = n-2; start >= 0; start--){
            
            int mini = INT_MAX-1;

            for(int i = 1; i <= nums[start]; i++){
                if(start + i >= n)
                    continue;
                int ans = 1 + memo[start+i];
                mini = min(mini, ans);
            }
            memo[start] = mini;
        }

        return memo[0];

       //return helper(nums, 0, nums.size()-1, memo); 
    }
};