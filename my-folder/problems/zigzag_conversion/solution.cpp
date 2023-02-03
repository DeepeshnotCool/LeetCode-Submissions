class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> vs(numRows, "");
        int index = 0;
        bool flag = false;
        for(int i = 0; i < s.size(); i++){
            if(index == 0 || index == numRows-1)
                flag = !flag;
            vs[index] += s[i];
            if(flag)
                index++;
            else
                index--;
        }
        string newS = "";
        for(auto it: vs){
            newS += it;
        }
        return newS;
    }
};