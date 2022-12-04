class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans=0;
        set<int> st;
        int l = 0, r = skill.size()-1;
        while(l < r)
        {
            int prod = skill[l] * skill[r];
            ans += prod;
            st.insert(skill[l] + skill[r]);
            l++;
            r--;
            if(st.size()>1)
                return -1;
        }
        return ans;
    }
};