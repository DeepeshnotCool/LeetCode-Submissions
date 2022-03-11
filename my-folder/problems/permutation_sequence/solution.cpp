class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1; i <= n; i++)
        {
            s += to_string(i); 
        }
        vector<string> v;
        do
        {
            v.push_back(s);
        }while(next_permutation(s.begin(), s.end()));
        return v[k-1];
    }
};