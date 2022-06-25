class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool flag = true;
        for(auto it : s){
            if(it == '|'){
                flag = !flag;
            }
            if(flag){
                if(it == '*')
                    count++;
            }
        }
        return count;
        
    }
};