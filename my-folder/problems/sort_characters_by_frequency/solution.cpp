class Solution {
public:

    static bool cmp(pair<char, int> &p1, pair<char, int> &p2){
        return p1.second > p2.second;
    }

    string frequencySort(string s) {
        map<char, int> m;
        for(auto it: s){
            m[it]++;
        }
        string ans = "";
        vector<pair<char, int>> v;
        for (auto it : m) {
            v.push_back(it);
        }

        sort(v.begin(), v.end(), cmp);

        for(auto it : v){
            //cout<<it.first;
            for(int i = 0; i < it.second; i++){
                ans += it.first;
            }
        }
        return ans;
    }
};