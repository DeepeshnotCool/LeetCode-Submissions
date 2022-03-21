class Solution {
public:
    
    int helper(string word1, string word2, vector<vector<int>> &v){
        
        if(word1.size() == 0 || word2.size() == 0){            
            return max(word1.size(), word2.size());
        }
        
        int m = word1.size();
        int n = word2.size();
        
        if(v[m][n] != -1){
            return v[m][n];
        }
        else{
            if(word1[0] == word2[0]){
                v[m][n] = v[m-1][n-1] = helper(word1.substr(1), word2.substr(1), v);
                return v[m][n];
            }
            else{
                v[m-1][n] = helper(word1.substr(1), word2, v);
                int _insert = 1 + v[m-1][n];
                v[m][n-1] = helper(word1, word2.substr(1), v);
                int _delete = 1 + v[m][n-1];
                v[m-1][n-1] = helper(word1.substr(1), word2.substr(1), v);
                int _replace = 1 + v[m-1][n-1];
                v[m][n] = min(_insert, min(_delete, _replace));
                return v[m][n];
            }
        }    
    }
    
    
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> v(m+1, vector<int>(n+1, -1));
        return helper(word1, word2, v);
    }
};