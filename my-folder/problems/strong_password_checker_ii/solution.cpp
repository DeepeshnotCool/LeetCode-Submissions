class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size() < 8)
            return false;
        bool up = false, low = false, dig = false, sp = false;
        for(int i = 0; i < password.size(); i++){
            if(!up && isupper(password[i]))
                up = true;
            if(!low && islower(password[i]))
                low = true;
            if(!dig && isdigit(password[i]))
                dig = true;
            if(!sp && !isalpha(password[i]) && !isdigit(password[i]))
                sp = true;
        }
        for(int i = 1; i < password.size(); i++)
            if(password[i] == password[i-1])
                return false;
        if(up && low && dig && sp)
            return true;
        return false;
    }
};