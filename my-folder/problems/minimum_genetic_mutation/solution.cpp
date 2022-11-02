



class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> v{'A', 'C', 'G', 'T'};
        set<string> s;
        for(auto it: bank){
            s.insert(it);
        }
        queue<pair<string,int>> q;
        q.push({start, 0});

        while(!q.empty()){
            string word = q.front().first;
            int mutation = q.front().second;
            q.pop();
            for(int i = 0; i < 8; i++){
                char temp = word[i];
                for(int j = 0; j < 4; j++){
                    word[i] = v[j];
                    if(s.find(word) != s.end()){
                        if(word == end)
                            return mutation + 1;
                        s.erase(word);
                        q.push({word,mutation+1});
                    }
                }
                word[i] = temp;
            }
        }
        return -1;
    }
};