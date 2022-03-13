class Solution {
public:
    bool isPerfectSquare(int num) {
        int val = sqrt(num);
        if(val*val == num)
            return true;
        return false;
    }
};