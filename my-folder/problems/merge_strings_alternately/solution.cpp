class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        int n = max(s1,s2);
        
        string s = "";
        for(int i = 0; i < n; i++)
        {
            if(i < s1)
                s += word1[i];
            if(i < s2)
                s += word2[i];
        }
        return s;
    }
};