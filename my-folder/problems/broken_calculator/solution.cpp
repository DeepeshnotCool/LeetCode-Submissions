class Solution {
public:
    int helper(int startValue, int target){
        if(startValue > target){
            return startValue - target;
        }
        if(startValue == target)
            return 0;
        int ans = 0;
        if(target & 1)
            ans =  1 + helper(startValue, target + 1);
        else
            ans = 1 + helper(startValue, target/2);
        return ans;
    }
    
    int brokenCalc(int startValue, int target) {
        return helper(startValue, target);
    }
};