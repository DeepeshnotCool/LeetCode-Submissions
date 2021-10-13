class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathvis)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pathvis))
                    return true;
            }
            else
            {
                if(pathvis[it])
                {
                    return true;
                }
            }
        }
        pathvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // cycle detection Directed graph 
        vector<int> adj[numCourses];
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> pathvis(numCourses,0);
        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pathvis))
                    return false;
            }
        }
        return true;
    }
};