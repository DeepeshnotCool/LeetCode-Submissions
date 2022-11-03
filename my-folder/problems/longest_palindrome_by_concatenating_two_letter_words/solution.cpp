class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       
        map<string, int> m;
        int count = 0;
        for(auto it: words){
            string rev = it;
            reverse(rev.begin(), rev.end());
            if(m[rev]){
                count += 4;
                m[rev]--;
            } else{
                m[it]++;
            }
        }

        for(auto it: m){
            if(it.first[0] == it.first[1] && it.second > 0){
                count += 2;
                break;
            }
        }
        return count;
    }
};