class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for(auto it: ransomNote){
            m[it]++;
        }   

        for(auto it: magazine){
            m[it]--;
        }
        for(auto it: m){
            cout<<it.second<<endl;
            if(it.second > 0)
                return false;
        }
        return true;
    }
};