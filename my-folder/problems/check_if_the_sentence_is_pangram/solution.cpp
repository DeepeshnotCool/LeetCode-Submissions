class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<char> v{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        int count = 0;
        for(auto it : v){
            int found = sentence.find(it);
            if(found != string::npos){
                count++;
            }
        }
        if(count < 26)
            return false;
        return true;
    }
};