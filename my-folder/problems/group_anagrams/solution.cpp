class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(s);
        }
        
        vector<vector<string>> v;
        for(auto it : m)
        {
            v.push_back(it.second);
        }
        return v;
        
        
        
    }
};