class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;
        set<string> exist;
        set<string> wordListD;
        for(auto it:wordList){
            wordListD.insert(it);
        }
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                if(front == endWord)
                    return ans+1;
                for(int i = 0; i < beginWord.size(); i++){
                    char temp = front[i];
                    for(int j = 0; j < 26; j++){
                        front[i] = char(j +'a');
                        bool flag = false;

                        if(wordListD.find(front) != wordListD.end()){
                            if(exist.find(front) == exist.end()){
                                q.push(front);
                                exist.insert(front);
                            }
                        }

                        // for(auto it: wordList){
                        //     if(front == it){
                        //         for(auto it1: exist){
                        //             if(it1 == front){
                        //                 flag = true;
                        //                 break;
                        //             }
                        //         }
                        //         if(!flag){
                        //             q.push(front);
                        //             exist.push_back(front);
                        //         }
                        //         break;
                        //     }
                        // }
                    }
                    front[i] = temp;
                }
            }
            ans++;
        }
        return 0;
    }
};