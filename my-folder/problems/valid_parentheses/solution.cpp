class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for(auto it : s)
        {
            if(it == '(' || it == '{' || it == '[')
            {
                sc.push(it);
            }
            if(!sc.empty())
            {
                if(it == ')')
                {
                    char ch = sc.top();
                    if(ch == '(')
                        sc.pop();
                    else
                        return false;
                }
                if(it == '}')
                {
                    char ch = sc.top();
                    if(ch == '{')
                        sc.pop();
                    else
                        return false;
                }
                if(it == ']')
                {
                    char ch = sc.top();
                    if(ch == '[')
                        sc.pop();
                    else
                        return false;
                }
            }
            else
                return false;
        }
        if(!sc.empty())
            return false;
        return true;
    }
};