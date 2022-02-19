class Solution {
public:
    vector<vector<int>> generateMatrix(int n1) {
        vector<vector<int>> matrix(n1,vector<int> (n1,0)); 
        int m = matrix.size();
        int n = matrix[0].size();
        
        int sr = 0;
        int sc = 0;
        int k = 1;
        while(sr < m &&  sc < n)
        {
            for(int i = sc; i < n; i++)
            {
                matrix[sr][i] = k;
                k++;
            }
            sr++;
            for(int i = sr; i < m; i++)
            {
                matrix[i][n-1] = k;
                k++;
            }
            n--;
            if(sr < m)
            {
                for(int i = n-1; i >= sc; i--)
                {
                    matrix[m-1][i] = k;
                    k++;
                }
                m--;
            }
            
            if(sc < n)
            {
                for(int i = m-1; i >= sr; i--)
                {
                    matrix[i][sc] = k;
                    k++;
                } 
                sc++;
            }
        }
        return matrix;

    }
};