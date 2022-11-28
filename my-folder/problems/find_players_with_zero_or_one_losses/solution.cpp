class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        for(auto it: matches){
            if(!m.count(it[0]))
                m[it[0]] = 0;
            m[it[1]]++;
        }

        vector<int> v1, v2;
        for(auto it: m){
            if(it.second == 0)
                v1.push_back(it.first);
            if(it.second == 1)
                v2.push_back(it.first);
        }

        vector<vector<int>> v;
        v.push_back(v1);
        v.push_back(v2);
        return v;
    }
};

