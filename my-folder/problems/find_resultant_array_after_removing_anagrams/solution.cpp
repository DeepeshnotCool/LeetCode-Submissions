class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        map<string, string> m;
        vector<string> v;
        for(auto it : words){
            string temp = it;
            sort(it.begin(), it.end());
            if(m.count(it) == 0){
                m.clear();
                m[it] = temp;
                v.push_back(temp);
            }
        }
        return v;
    }
};