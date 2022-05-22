class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for(auto it: s){
            if(it == letter)
                count++;
        }
        cout<<count;
        return floor((count * 100)/s.size());
    }
};