class Solution {
public:

    void helper(vector<string>& arr, int index, string s, int& ans){
        if(s.size() > ans){
            ans = s.size();
        }
        for(int i = index; i < arr.size(); i++){
            string temp = s + arr[i];
            set<char> st(begin(temp), end(temp));
            if(st.size() == temp.size()){
                helper(arr, i + 1, temp, ans);
            }
        }
    }

    int maxLength(vector<string>& arr) {
        int ans = 0;
        helper(arr, 0, "", ans);
        return ans;   
    }
};