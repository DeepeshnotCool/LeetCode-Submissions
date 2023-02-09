class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        set<string> count[26];
        for(auto it: ideas){
            count[it[0] - 'a'].insert(it.substr(1));
        }   
        long long ans = 0;
        for(int i = 0; i < 26; i++){
            for(int j = i+1; j < 26; j++){
                long long c1 = 0, c2 = 0;
                for(auto it: count[i]){
                    if(!count[j].count(it))
                        c1++;
                }
                for(auto it: count[j]){
                    if(!count[i].count(it))
                        c2++;
                }
                ans += c1 * c2;
            }
        }
        return ans * 2;
    }
};

