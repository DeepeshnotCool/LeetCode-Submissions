class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, size = 0;
        for(auto it: nums){
            if(!(it & 1) && (it % 3 == 0)){
                sum += it;
                size++;
            }
        }
        if(size == 0)
            return 0;
        return sum/size;
    }
};