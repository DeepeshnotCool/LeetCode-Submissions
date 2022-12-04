class Solution {
public:
    bool isCircularSentence(string sentence) {
       int n=sentence.length();
        if(sentence[0] != sentence[n-1])
            return false;
        char ch;
        for(int i=0; i < n; i++)
        {
            if(sentence[i] != ' ')
             ch = sentence[i];
            else{
                if(sentence[i+1]!=ch)
                    return false;
            }
            
        }
        return true;
    }

};