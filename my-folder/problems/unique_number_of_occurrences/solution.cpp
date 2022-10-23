class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        for(auto it: arr){
            m[it]++;
        }
        set<int> s;
        for(auto it: m){
            s.insert(it.second);
        }
        if(s.size() == m.size())
            return true;
        return false;
    }
};