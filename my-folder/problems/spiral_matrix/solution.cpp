class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int sr = 0;
        int sc = 0;
        
        while(sr < m &&  sc < n)
        {
            for(int i = sc; i < n; i++)
            {
                v.push_back(matrix[sr][i]);
            }
            sr++;
            for(int i = sr; i < m; i++)
            {
                v.push_back(matrix[i][n-1]);
            }
            n--;
            if(sr < m)
            {
                for(int i = n-1; i >= sc; i--)
                {
                    v.push_back(matrix[m-1][i]);
                }
                m--;
            }
            
            if(sc < n)
            {
                for(int i = m-1; i >= sr; i--)
                {
                    v.push_back(matrix[i][sc]);
                } 
                sc++;
            }
        }
        
        return v;
        
    }
};