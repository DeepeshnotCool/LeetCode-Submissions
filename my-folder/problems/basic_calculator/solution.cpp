class Solution {
public:
    
    int calculate(string s) 
    {
        stack<int>st; 
        int ans=0; 
        long long cur_val = 0, sign=1; 
       
        for (char c : s) 
        { 
            if(isdigit(c)) 
            {
                cur_val = 10*cur_val + (c-'0'); 
            }
            else if(c=='+')
            {
                ans += cur_val*sign; 
                cur_val = 0;
                sign = 1;   
            }
            else if(c=='-')
            {
                ans += cur_val*sign; 
                cur_val = 0; 
                sign = -1; 
            }
            else if(c=='(')
            {
                st.push(ans);    
                st.push(sign); 
                ans = 0; 
                sign = 1;
            }
            else if(c==')')
            { 
                ans += cur_val*sign; 
                cur_val = 0;
                
                ans = ans*st.top(); 
                st.pop();
                ans = ans + st.top();
                st.pop();
            }
        }
        
        ans += cur_val*sign; 
        return ans; 
    }
};