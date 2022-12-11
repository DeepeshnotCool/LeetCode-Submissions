class Solution {
    public int deleteGreatestValue(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int sum = 0;
        int[][]vis = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vis[i][j] = 0;
            }
        }
        
        
        for(int t = 0; t < n; t++){
            int ans = Integer.MIN_VALUE;
            for(int i = 0; i < m; i++){
                int maxi = Integer.MIN_VALUE;
                int ind = 0;
                for(int j = 0; j < n; j++){
                    if(vis[i][j] == 0){
                        ans = Math.max(ans, grid[i][j]);
                        if(grid[i][j] > maxi){
                            maxi = grid[i][j];
                            ind = j;
                        }
                    }
                }
                vis[i][ind] = 1;
            }
            sum += ans;
        }
        return sum;
    }
}