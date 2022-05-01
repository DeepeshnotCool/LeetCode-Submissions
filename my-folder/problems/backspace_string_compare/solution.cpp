class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "";
        string t1 = "";
        for(auto it : s){
            if(it != '#')
                s1 += it;
            else if(s1.size() != 0){
                s1 = s1.substr(0,s1.size()-1);
            }
        }
        for(auto it : t){
            if(it != '#')
                t1 += it;
            else if(t1.size() != 0){
                t1 = t1.substr(0,t1.size()-1);
            }
        }
        if(s1 == t1)
            return true;
        return false;
    }
};