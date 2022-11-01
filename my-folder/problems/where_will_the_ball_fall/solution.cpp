class Solution {
public:

    int helper(int row, int col, int n, int m, vector<vector<int>>& grid){
        if(row == m)
            return col;
        int new_col = col + grid[row][col];
        if(new_col == n || new_col == -1 || grid[row][new_col] != grid[row][col])
            return -1;
        else    
            return helper(row + 1, new_col, n, m, grid);
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v;
        for(int i = 0; i < n; i++){
            v.push_back(helper(0,i,n,m,grid));
        }
        return v;
    }
};