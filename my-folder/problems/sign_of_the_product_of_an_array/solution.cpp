class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countneg = 0;
        for(auto it: nums)
        {
            if(it == 0)
                return 0;
            if(it < 0)
                countneg++;
        }
        if(countneg % 2 == 0)
        {
            return 1;
        }
        return -1;
    }
};