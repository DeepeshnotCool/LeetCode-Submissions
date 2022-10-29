class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> v;
        map<string, int> m;
        
        for(auto it: dictionary){
            m[it]++;
        }
        
        for(auto it: queries){
            if(m[it]){
                v.push_back(it);
                continue;
            }
            for(auto it1: dictionary){
                int count = 0;
                for(int i = 0; i < it.size(); i++){
                    if(it1[i] != it[i])
                        count++;
                }
                if(count <= 2){
                    v.push_back(it);
                    break;
                }
            }
        }
        return v;
    }
};