class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char firstChar = s[0];
        char tempCh = ' ';
        string s1,s2;
        s1 = s;
        s2 = s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '9' && tempCh == ' ') {
                tempCh = s[i];
            }
            if(s[i] == firstChar) {
                s2[i] = '0';
            }
        }
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == tempCh) {
                s1[i] = '9';
            }
        }
        return stoi(s1) - stoi(s2);
    }
};