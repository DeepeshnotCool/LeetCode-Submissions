class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> st;
        map<int, int> m;
        for(auto it : trust){
            st.insert(it[0]);
            m[it[1]]++;
        }

        for(int i = 1; i <= n; i++){
            if(st.find(i) == st.end() && m[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};