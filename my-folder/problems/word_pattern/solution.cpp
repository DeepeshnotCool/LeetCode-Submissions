class Solution {
public:
    bool wordPattern(string pattern, string str) {

        if(pattern.size() ==0 || str.size()==0) return false;        
        map<string,char> dic;
        vector<string> S; 
        set<char> pool; 
        string temp;
        for(auto c:str){ 
            if(c!=' '){
                temp = temp + c;
            }else{
                S.push_back(temp);
                temp="";
            }
        }
        
        S.push_back(temp);
        if(pattern.size() != S.size()) return false;
        
        int i = 0;
        for(auto c : S){
            if(dic.find(c) == dic.end() && !pool.count(pattern[i])){
                dic[c] = pattern[i];
                pool.insert(pattern[i]);
            }else{
                if(dic[c] != pattern[i]) return false;
            }
            i++;
        }
        return true;
    }
};