class node {
public:
    int x, y, m;
    node(int _x, int _y, int _m)
    {
        x = _x;
        y = _y;
        m = _m;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<node> q;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(node(i,j,0));     
                }   
                if(grid[i][j] != 0)
                    count++;
            }
        }
        int best = 0;
        int rottencount = 0;
        while(!q.empty())
        {
            int x1 = q.front().x;
            int y1 = q.front().y;
            int m1 = q.front().m;
            best = max(m1,best);
            q.pop();
            rottencount++;
            int xa[4] = {-1,0,1,0};
            int ya[4] = {0,-1,0,1};
            for(int i = 0; i < 4; i++)
            {
                int nextX = xa[i] + x1;
                int nextY = ya[i] + y1;
                
                if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && grid[nextX][nextY] == 1)
                {
                    grid[nextX][nextY] = 2;
                    q.push(node(nextX,nextY,m1+1));
                }
            }
        }
        if(rottencount == count)
        {
            return best;
        }
        else
        {
            return -1;
        }
    }
};