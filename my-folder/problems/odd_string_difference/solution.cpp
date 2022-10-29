class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, vector<string>> m;
        for(auto it: words){
            vector<int> v;
            //cout<<it<<" "; 
            for(int i = 1; i < it.size(); i++){
                //cout<<it[i]<<" ";
                int diff = it[i]-it[i-1];
                //cout<<diff<<" ";
                v.push_back(diff);
            }
            //cout<<endl;
            m[v].push_back(it);
        }
        for(auto it: m){
            if(it.second.size() == 1){
                return it.second[0];
            }
        }
        return "";
    }
};