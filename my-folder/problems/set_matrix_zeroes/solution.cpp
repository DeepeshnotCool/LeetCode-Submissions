class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> v(m, vector<int> (n,-1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] != 0){
                    continue;
                }
                for(int k = 0; k < n; k++){
                    v[i][k] = 0;
                }
                for(int k = 0; k < m; k++){
                    v[k][j] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] != -1){
                    matrix[i][j] = v[i][j];
                }
            }
        }
    }
};