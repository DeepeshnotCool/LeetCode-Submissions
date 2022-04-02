class Solution {
public:
    int count = 0;
    bool helper(int l, int r, string &s){
        if(l >= r)
            return true;
        if(s[l] == s[r])
            return helper(l+1, r-1, s);
        
        if(count == 1){
            return false;
        }
        else
            count++;
        return helper(l, r-1, s) || helper(l+1, r, s);
    }
    
    
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        return helper(l, r, s);
    }
};