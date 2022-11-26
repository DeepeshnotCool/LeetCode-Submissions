class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX, s = INT_MAX;
        if(nums.size() < 3)   
            return false;
        for(auto it : nums){
            if(it <= f)  
                f = it;
            else if(it <= s) 
                s = it;
            else    
                return true;
        }
        return false;
    }
};


