class Solution {
public:
    int countOdds(int low, int high) {
        int size = high - low - 1;
        if(low%2 == 0 && high%2 == 0)
        {
            if(low == high)
                return 0;
            return size/2 + 1;
        }
        if(low%2 != 0 && high%2 != 0)
        {
            if(low == high)
                return 1;
            return size/2 + 2;
        }
        return size/2 + 1;
    }
};