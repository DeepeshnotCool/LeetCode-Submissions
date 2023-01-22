class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int count0 = 0, count1 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0')
                count0++;
            else
                count1++;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == target[i])
                continue;
            else if(s[i] == '0' && target[i] == '1'){
                if(count1 >= 1){
                    s[i] = '1';
                    count1++;
                    count0--;
                }
                else
                    return false;
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == target[i])
                continue;
            else if(s[i] == '1' && target[i] == '0'){
                if(count1 > 1){
                    s[i] = '0';
                    count1--;
                    count0++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};