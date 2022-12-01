class Solution {
public:
    bool halvesAreAlike(string s) {
        if(s.size() & 1)
            return false;
        set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++){
            if(i < s.size()/2){
                if(st.find(s[i]) != st.end())
                    left++;
            } else{
                if(st.find(s[i]) != st.end())
                    right++;
            }
        }
        return left == right;
    }
};