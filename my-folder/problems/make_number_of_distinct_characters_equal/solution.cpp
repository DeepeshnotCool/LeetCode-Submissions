class Solution {
public:
    bool helper( vector<int> freq1, vector<int> freq2){
        map<int,int> m1, m2;
        for(int i =0; i < 26; i++){
            if(freq1[i] > 0)
                m1[i]++;
            if(freq2[i] > 0)
                m2[i]++;
        }
        return m1.size() == m2.size();
    }
    
    bool isItPossible(string word1, string word2) {
        vector<int> freq1(26,0), freq2(26,0);
        for(auto it : word1)
            freq1[it - 'a']++;
        for(auto it : word2)
            freq2[it - 'a']++;
        for(int i = 0; i < 26; i++){
            if(freq1[i] > 0){
                freq1[i]--;
                for(int j = 0; j < 26; j++){
                    if(freq2[j] > 0){
                        freq2[j]--;
                        freq2[i]++;
                        freq1[j]++;
                        bool temp = helper(freq1,freq2);
                        if(temp)
                            return true;
                        freq2[i]--;
                        freq2[j]++;
                        freq1[j]--;
                    }
                }
                freq1[i]++;
            }
        }
        return false;
        
    }
};


