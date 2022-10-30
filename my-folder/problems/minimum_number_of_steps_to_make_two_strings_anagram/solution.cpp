class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> m;
        for(auto it: t){
            m[it]++;
        }
        for(auto it: s){
            if(m[it]){
                m[it]--;
            }
        }
        int ans = 0;
        for(auto it: m){
            ans += it.second;
        }
        return ans;
    }
};