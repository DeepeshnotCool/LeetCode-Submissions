class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> v;
        for(auto it: nums){
            if(!(it & 1))
                v.push_back(it);
        }
        for(auto it: nums){
            if(it & 1)
                v.push_back(it);
        }
        return v;
    }
};