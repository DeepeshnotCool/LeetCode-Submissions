class Solution {
public:
    bool digitCount(string num) {
        map<int, int> m;
        for(int i = 0; i < num.size(); i++){
            int temp = num[i]- 48;
            m[temp]++;
            //cout<<temp<<endl;
        }
        
        for(int i = 0; i < num.size(); i++){
            //cout<<num[i]<<"-"<<m[i]<<endl;
            int temp = num[i] - 48;
            if(m[i] != temp)
                return false;
        }
        return true;    
    }
};