class Solution {
public:
    bool isPowerOfTwo(int n) {
        //cout<<log2(n);
        if(n <= 0)
            return false;
        if(log2(n) == floor(log2(n)))
            return true;
        return false;
    }
};