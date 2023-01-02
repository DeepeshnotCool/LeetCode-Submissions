class Solution {
public:
    bool detectCapitalUse(string word) {
        int countupper = 0, countlower = 0;
        for(auto it: word){
            if(isupper(it))
                countupper++;
            if(islower(it))
                countlower++;
        }
        if(countupper == word.size() || countlower == word.size())
            return true;
        if(isupper(word[0]) && countlower == word.size() - 1)
            return true;
        return false;
    }
};