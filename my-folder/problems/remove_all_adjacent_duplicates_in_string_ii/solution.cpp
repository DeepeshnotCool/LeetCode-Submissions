class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> v;
        for(auto it: s){
            if(v.size() == 0 || v[v.size()-1].first != it)
                v.push_back({it,1});
            else{
                v[v.size()-1].second++;
                if(v[v.size()-1].second == k)
                    v.pop_back();
            }
        }
        
        string s1 = "";
        for(auto it: v){
            while(it.second--)
                s1 += it.first;
            
        }
        
        return s1;
        
        
    }
};