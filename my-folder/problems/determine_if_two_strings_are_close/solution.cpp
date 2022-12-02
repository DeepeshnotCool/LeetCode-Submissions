class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freqW1(26,0), freqW2(26,0);
        set<char> s1, s2;
        for(auto it: word1){
            freqW1[it - 'a']++;
            s1.insert(it);
        }
        for(auto it: word2){
            freqW2[it - 'a']++;
            s2.insert(it);
        }
        sort(freqW1.begin(), freqW1.end());
        sort(freqW2.begin(), freqW2.end());
        return freqW1 == freqW2 && s1 == s2;
    }
};