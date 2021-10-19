class Solution {
private:
    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, int color, vector<int> &col)
    {
        visited[node] = true;
        col[node] = color;
        for(auto it : graph[node])
        {
            if(!visited[it])
            {
                if(!dfs(graph,visited,it,!color,col))
                    return false;
            }
            else
            {
                if(col[it] == color)
                    return false;
            }
        }
        return true;
    }
//     bool bfs(vector<vector<int>> &graph, vector<bool> &visited, int node, int color, vector<int> &col)
//     {
//         queue<pair<int,int>> q;
//         q.push({node,color});
//         visited[node] = true;
//         col[node] = color;
//         while(!q.empty())
//         {
//             int xnode = q.front().first;
//             int xcolor = q.front().second;
//             q.pop();
//             for(auto it : graph[xnode])
//             {
//                 if(!visited[it])
//                 {
//                     q.push({it,!xcolor});
//                     visited[it] = true;
//                     col[it] = !xcolor;
//                 }
//                 else
//                 {
//                     if(col[it] == xcolor)
//                     {
//                         return false;
//                     }
//                 }
//             }
//         }
//         return true;
        
//     }
public:
    bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<bool> visited(n,false);
//         vector<int> col(n,-1);
//         for(int i = 0; i < n; i++)
//         {
//             if(!visited[i])
//                 if(!bfs(graph,visited,i, -1,col))
//                     return false;
//         }
//         return true;
        
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<int> col(n,-1);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                if(!dfs(graph,visited,i, 0,col))
                    return false;
        }
        return true;
    }
};