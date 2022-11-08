class Solution {
public:

    string helper(string s){
        if(s.size() <= 1)
            return s;
        if(s.size() == 2){
            if(abs(s[0] - s[1]) == 32)
                return "";
            else
                return s;
        }

        string temp = helper(s.substr(1,s.size()));
        if(abs(s[0] - temp[0]) == 32){
            return temp.substr(1,temp.size());
        } else{
            return s[0] + temp;
        }
    }

    string makeGood(string s) {
        return helper(s);
        // while(true){
        //     string ans = "";
        //     set<int> st;
        //     bool flag = false;
        //     for(int i = 0; i < s.size();){
        //         if(abs((s[i] - s[i+1])) == 32){
        //             st.insert(i);
        //             st.insert(i+1);
        //             i+=2;
        //             flag = true;
        //         }else{
        //             i++;
        //         }
        //     }
        //     if(!flag)
        //         break;

        //     for(int i = 0; i < s.size(); i++){
        //         if(st.find(i) != st.end()){
        //             continue;
        //         } else{
        //             ans += s[i];
        //         }
        //     }
        //     cout<<ans;
        //     s = ans;
        // }
        // return s;
    }
};