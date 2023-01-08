class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countPos = 0, countNeg = 0;
        for(auto it: nums){
            if(it < 0){
                countNeg++;
            } else if(it > 0){
                countPos++;
            }
        }
        return max(countPos, countNeg);
        
    }
};