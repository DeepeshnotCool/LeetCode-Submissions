class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(auto x: s)
        {
            if(isalpha(x) || isdigit(x))
            {
                if(isupper(x))
                {
                    s1 += tolower(x);
                    continue;
                }
                
                s1 += char(x);
            }
        }
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        cout<<s1<<endl<<s2;
        if(s2 == s1)
            return true;
        return false;
        
        
        
    }
};