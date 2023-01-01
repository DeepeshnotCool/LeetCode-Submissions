class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans = 0;
        int n = s.size();
        int temp = 0;
        string str = to_string(k);
        int len = str.size();
        if(len == 1){
            for(int i = 0; i < s.size(); i++){
                if(s[i]-'0' > k)
                    return -1;
            }
            return s.size();
        }
        for(int i = 0; i < s.size();){
            int x = min(i + len, n);
            string sub = s.substr(i,x);
            if(sub <= str){
               i+=len;
            } else{
                i+=(len-1);
            }
            ans++;
        }
        return ans;
    }
};