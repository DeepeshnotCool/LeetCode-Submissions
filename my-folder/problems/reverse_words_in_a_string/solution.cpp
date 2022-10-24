class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        bool flag = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                temp += s[i];
                flag = true;
            } else{
                if(temp != ""){
                    st.push(temp);
                }
                temp = "";
                flag = false;
            }
        }
        if(flag)
            st.push(temp);
        string ans = "";
        while(!st.empty()){
            string ss = st.top();
            ans += ss + " ";
            st.pop();
        }
        return ans.substr(0, ans.size() - 1);
    }
};