class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        

        map<string,vector<string>> m;
        for(int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            //sort(strs[i].begin(), strs[i].end());
            vector<int> alphacount(26,0);
            for (auto it : s) {
                alphacount[it - 'a']++;
            }
            string temp = "";
            for (int j = 0; j < 26; j++) {
                for(int k = 0; k < alphacount[j]; k++)
                    temp += to_string(j + 'a');
            }
            m[temp].push_back(s);
        }
        
        vector<vector<string>> v;
        for(auto it : m)
        {
            v.push_back(it.second);
        }
        return v;






    }
};