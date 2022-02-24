class Solution {
public:
    /*
    int lcs(string text1, string text2, vector<vector<int>>& v)
    {
        if(text1.size() == 0 || text2.size() == 0)
            return 0;
        int m = text1.size();
        int n = text2.size();
        if(v[m][n] != -1)
        {
            return v[m][n];
        }
        if(text1[0] == text2[0])
        {
            
            v[m-1][n-1] = lcs(text1.substr(1), text2.substr(1), v);
            v[m][n] = 1 + v[m-1][n-1];
            return v[m][n];
        }
        else
        {
            v[m][n-1] = lcs(text1, text2.substr(1), v);
            v[m-1][n] = lcs(text1.substr(1), text2, v);
            //v[m-1][n-1] = longestCommonSubsequence(text1.substr(1), text2.substr(1));
            v[m][n] = max(v[m][n-1],v[m-1][n]);
            return v[m][n];
        }
    }
    */
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> v(m+1,vector<int> (n+1,-1));
        for(int i = 0; i <= n; i++)
        {
            v[0][i] = 0;
        }
        for(int i = 0; i <= m; i++)
        {
            v[i][0] = 0;
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(text1[m-i] == text2[n-j])
                    v[i][j] = 1 + v[i-1][j-1];
                else
                {
                    v[i][j] = max(v[i-1][j], v[i][j-1]);
                }
            }
        }
        return v[m][n];
        
        
        //return lcs(text1, text2, v);
    }
};