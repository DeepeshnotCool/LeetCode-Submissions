class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        string s1 = "";
        string s2 = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ' ')
                s1 += s[i];
            else
            {
                reverse(s1.begin(),s1.end());
                s2 += s1 + " ";
                s1 = "";
            }
        }
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] != ' ')
                s2 += s[i];
            else
                break;
        }
        return s2;
    }
};