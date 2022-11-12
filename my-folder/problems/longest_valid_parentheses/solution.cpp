class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> index;
        stack<char> par;
        index.push(-1);
        int maxi = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                par.push(s[i]);
                index.push(i);
            } else{
                if(par.empty())
                    index.push(i);
                else if(par.top() == '('){
                    index.pop();
                    par.pop();
                    int val = index.top();
                    maxi = max(maxi, i-val);
                }
                
            }
        }
        return maxi;

    }
};