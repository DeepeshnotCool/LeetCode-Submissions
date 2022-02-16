class Solution {
public:
    bool canWinNim(int n) {
        if(n%4 > 0 && n%4 <= 3)
        {
            return true;
        }
        return false;
    }
};