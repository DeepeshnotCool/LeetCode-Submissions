class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0], minSum = nums[0], curMax=0, curMin=0;
        int totalSum = 0;
        for(auto it : nums){
            curMax = max(curMax + it, it);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + it, it);
            minSum = min(minSum, curMin);
            totalSum += it;
        }
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};