class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.size() - 1;
        int bl = b.size() - 1;
        string s = "";
        int carry = 0;
        while(al >= 0 || bl >= 0 || carry){
            if(al >= 0) 
                carry += a[al--] == '1' ? 1 : 0;
            if(bl >= 0) 
                carry += b[bl--] == '1' ? 1 : 0;
            s += carry % 2 ? '1' : '0';
            carry /= 2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};