class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> m;
        for(auto it: words){
            m[it]++;
        }   

        int total = 0, odd = 0;
        for(auto it: m){
            if(it.first[0] == it.first[1]){
                total += (m[it.first]/2) * 2 * 2;
                odd = max(odd, (m[it.first] % 2) * 2);
            } else if(it.first[0] < it.first[1]){
                string rev = it.first;
                reverse(rev.begin(), rev.end());
                total += min(m[it.first], m[rev]) * 2 * 2;
            }
        }
        return total + odd;
    }
};