class Solution {
    bool helper(vector<int> freqS1, vector<int> freqS2){
        for(int i = 0; i < 26; i++){
            if(freqS1[i] != freqS2[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        
        int sizeS1 = s1.size();
        int sizeS2 = s2.size();
        if(s1.size() > s2.size())
            return false;
        vector<int> freqS1(26, 0);
        for(auto it: s1){
            freqS1[it - 'a']++;
        }

        vector<int> freqS2(26,0);
        int i = 0, j = 0;

        while(j < sizeS2){
            freqS2[s2[j]-'a']++;
            if(j-i+1 == sizeS1){
                if(helper(freqS1, freqS2))
                    return true;
            } 
            if(j-i+1 < sizeS1)
                j++;
            else{
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};