class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        while(k--){
            int temp = grid[m-1][n-1];
            for(int i = 0; i < m; i++){
                int temp1 = grid[i][n-1];
                for(int j = n-1; j > 0; j--){
                    grid[i][j] = grid[i][j-1];
                }
                grid[i][0] = temp;
                temp = temp1;
            }
        }
        return grid;
    }
};