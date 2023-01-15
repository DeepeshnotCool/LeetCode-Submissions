class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> v(n + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < queries.size(); i++){
            int row1 = queries[i][0], col1 = queries[i][1], row2 = queries[i][2], col2 = queries[i][3];
            for(int j = row1; j <= row2; j++){
                v[j][col1]++;
                v[j][col2 + 1]--;
            }
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < n; j++){
                v[i][j+1] += v[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int> (n,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = v[i][j];
            }
        }
        return ans;
    }
};