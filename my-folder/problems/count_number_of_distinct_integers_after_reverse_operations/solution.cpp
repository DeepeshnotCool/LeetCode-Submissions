class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        for(auto it: nums){
            s.insert(it);
            int rev = 0;
            while( it != 0)
            {
                rev = 10*rev + it%10;
                it /= 10;
            }
            s.insert(rev);
        }
        
        return s.size();
    }
};