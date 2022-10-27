class Solution {
public:
    int countOdds(int low, int high) {
        if((low & 1) && (high & 1)){
            return 1 + (high - low + 1)/2;
        }
        return (high - low + 1)/2;
    }
};