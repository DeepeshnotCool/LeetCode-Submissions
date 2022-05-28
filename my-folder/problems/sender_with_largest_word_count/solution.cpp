class Solution {
public:
    
    int wordCount(string s){
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                count++;
        }
        return count+1;
    }
    
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> m;
        for(int i = 0; i < senders.size(); i++){
            m[senders[i]] += wordCount(messages[i]);
        }
        int maxi = INT_MIN;
        string ans = "";
        for(auto it : m){
            if(it.second >= maxi){
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
        
        
    }
};