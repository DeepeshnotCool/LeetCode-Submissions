class DSU
{
    private:
    vector<int> parent,size;
    public:
    DSU(int n)
    {
        for(int i = 0; i < n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int findPar(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    void unionSize(int a, int b)
    {
        int pa = findPar(a);
        int pb = findPar(b);
        if(pa == pb)
        {
            return;
        }
        if(size[pa] < size[pb])
        {
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        else
        {
            parent[pb] = pa;
            size[pa] += size[pb];
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        cout<<n<<m;
        DSU dsu(n*m);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int index1 = i*n+j;
                if(grid[i][j] == '0')
                    continue;
                int dx[4] = {-1,0,1,0};
                int dy[4] = {0,-1,0,1};
                for(int k = 0; k < 4; k++)
                {
                    int nextX = i+dx[k];
                    int nextY = j+dy[k];
                    int index2 = nextX*n+nextY;
                    if(nextX >= 0 && nextY >= 0 && nextX < m && nextY < n && grid[nextX][nextY] == '1' && dsu.findPar(index1) != dsu.findPar(index2))
                    {
                        // cout<<"next"<<nextX<<" "<<nextY<<endl;
                        // cout<<"island"<<grid[nextX][nextY]<<endl;
                        // cout<<"index"<<index1<<" "<<index2<<endl;
                        // cout<<"Upar"<<dsu.findPar(index1)<<" "<<dsu.findPar(index2)<<endl;
                        dsu.unionSize(index1,index2);
                    }
                }
            }
        }
        set<int> s;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                    s.insert(dsu.findPar(i*n+j));
            }
        }
        // for(auto it : s)
        //     cout<<it<<" ";
        return s.size();
    }
};