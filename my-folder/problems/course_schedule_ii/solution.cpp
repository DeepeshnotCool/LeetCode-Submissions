class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> v;
        while(!q.empty())
        {
            int front = q.front();
            v.push_back(front);
            q.pop();
            for(auto it : adj[front])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(v.size() != numCourses)
        {
            vector<int> v1;
            return v1;
        }
        return v;
    }
};