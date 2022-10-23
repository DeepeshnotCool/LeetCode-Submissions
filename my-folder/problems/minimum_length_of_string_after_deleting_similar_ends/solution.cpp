class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size()-1;
        map<char, bool> m;
        m['a'] = false;
        m['b'] = false;
        m['c'] = false;
        int count = 0;
        while(i < j){
            
            if(m[s[i]] == false && m[s[j]] == false && s[i] != s[j]){
                break;
            }

            if(m[s[i]] == false && m[s[j]] == false){
                m[s[i]] = true;
                if(s[i] == 'a'){
                    m['b'] = false;
                    m['c'] = false;
                } else if(s[i] == 'b'){
                    m['a'] = false;
                    m['c'] = false;
                } else if(s[i] == 'c'){
                    m['a'] = false;
                    m['b'] = false;
                }
            } 

            if(m[s[i]]){
                i++;
                count++;
            }
            if(m[s[j]]){
                j--;
                count++;
            }
        }
        int n = s.size();
        if(m[s[i]] && (n & 1))
            count++;
        int ans = s.size() - count;
        if(ans < 0)
            return 0;
        return ans;
    }
};