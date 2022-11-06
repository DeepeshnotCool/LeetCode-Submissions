class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        if(k == 1){
            string ans = s;
            s += s;
            for(int i = 0; i < n; i++){
                ans = min(ans, s.substr(i, n)); 
            }
            return ans;
        }
        sort(s.begin(),s.end());
        return s;

    }
};
