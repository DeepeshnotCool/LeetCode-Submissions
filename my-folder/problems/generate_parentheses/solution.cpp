class Solution {
public:
    
    void helper(vector<string> &v, int open, int close, string output){
        if(open == 0 && close == 0){
            v.push_back(output);
            return;
        }
        

        if(open != 0){
            string temp = output;
            temp += "(";
            //cout<<output<<" ";
            helper(v, open - 1, close, temp);
        }
        
        
        if(close > open){
            string temp = output;
            temp += ")";
            //cout<<output<<" ";
            helper(v, open, close - 1, temp);
        }
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int open = n;
        int close = n;
        string output = "";
        helper(v, open, close, output);
        return v;
    }
};