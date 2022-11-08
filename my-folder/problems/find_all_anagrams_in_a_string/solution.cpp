class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;

        if(p.size() > s.size())
            return v;

        int sizeP = p.size();
        vector<int> freqP(26,0);
        for(int i = 0; i < sizeP; i++){
            freqP[p[i] - 'a']++;
        }

        vector<int> freqS(26,0);
        for(int i = 0; i < sizeP; i++){
            freqS[s[i] - 'a']++;
        }

        bool flag = true;
        for(int i = 0; i < 26; i++){
            if(freqP[i] != freqS[i]){
                flag = false;
                break;
            }
        }

        if(flag){
            v.push_back(0);
        }

        for(int i = sizeP; i < s.size(); i++){
            freqS[s[i-sizeP] - 'a']--;
            freqS[s[i]-'a']++;
            flag = true;
            for(int i = 0; i < 26; i++){
                if(freqP[i] != freqS[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                v.push_back(i - sizeP + 1);
            }
        }
        return v; 
    }
};