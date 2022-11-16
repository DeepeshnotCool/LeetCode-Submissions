class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string s = "", l = strs[0], r = strs[strs.size()-1];
        for(int i = 0; i < l.size(); i++){
            if(l[i] == r[i] && l != "")
                s += l[i];
            else   
                break;
        }
        return s;
    }
};




