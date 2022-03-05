class Solution {
public:
    string interpret(string command) {
        string s = "";
        int i = 0;
        while(i < command.size())
        {
            cout<<i<<" ";
            if(command[i] == 'G')
            {
                s += command[i];
                i++;
            }
            else if(command[i] == '(' && command[i+1] == 'a')
            {
                s += "al";
                i += 4;
            }
            else if(command[i] == '(')
            {
                s += "o";
                i += 2;
            }
            
        }
        return s;
    }
};