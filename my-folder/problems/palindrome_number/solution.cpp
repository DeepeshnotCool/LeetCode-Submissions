class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        int num = x;
        string s = "";
        while(num != 0)
        {
            s += to_string(num%10);
            num /= 10;
        }
        //cout<<s;
        string s1 = to_string(x);
        //cout<<s1;
        if(s1 == s)
            return true;
        return false;
    }
};