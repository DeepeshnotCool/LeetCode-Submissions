class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, pair<int , int>>> q;
        q.push({0,{entrance[0], entrance[1]}});
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[entrance[0]][entrance[1]] = 1;
        while(!q.empty()){
            int step = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};

            for(int i = 0; i < 4; i++){
                int nextX = x + dx[i];
                int nextY = y + dy[i];

                if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && maze[nextX][nextY] == '.' && !visited[nextX][nextY]){
                    q.push({step + 1,{nextX, nextY}});
                    visited[nextX][nextY] = 1;

                    if(nextX == n-1 || nextX == 0 || nextY == m-1 || nextY == 0)
                        return step + 1;
                }
            }
        }
        return -1;
    }
};