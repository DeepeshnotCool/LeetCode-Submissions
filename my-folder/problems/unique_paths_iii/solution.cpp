class Solution {
public:
    void helper(int i, int j, vector<vector<int>>& grid, int e, int &ans) {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == -1) return;
        if(grid[i][j] == 2) {
            if(!e) ans++;
            return;
        } 
        grid[i][j] = -1;
        helper(i + 1, j, grid, e - 1, ans);
        helper(i - 1, j, grid, e - 1, ans);
        helper(i, j + 1, grid, e - 1, ans);
        helper(i, j - 1, grid, e - 1, ans);
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int e = 0, x, y, ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1)
                    x = i, y = j;
                else if(grid[i][j] == 0) 
                    e++;
            }
        }
        helper(x, y, grid, e + 1, ans);
        return ans;      
    }
};