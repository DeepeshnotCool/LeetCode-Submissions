class Solution {
public:

    string helper(string s){
        int count = 1;
        string ans;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                count++;
            } else{
                string ch = to_string(count);
                ans += ch;
                ans += s[i-1];
                count = 1; 
            }
        }
        string ch = to_string(count);
        ans += ch;
        ans += s[s.size()-1];
        return ans;
    }

    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++){
            string temp = helper(ans);
            ans = temp;
        }

        return ans;
    }
};