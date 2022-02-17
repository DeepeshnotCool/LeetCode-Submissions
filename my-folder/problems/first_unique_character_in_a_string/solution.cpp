class Solution {
public:
    int firstUniqChar(string s) {
        int c[26];
        for(int i = 0; i < 26; i++)
        {
            c[i] = 0;
        }
        for(int i = 0; i < s.size(); i++)
        {
            c[s[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(c[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};