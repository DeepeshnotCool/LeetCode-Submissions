class Solution {
public:


    int minFlipsMonoIncr(string s) {
        int countZero = 0, countOne = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1')
                countOne++;
            else
                countZero++; 
            if(countZero > countOne)
                countZero = countOne;
        }
        return countZero;
    }
};