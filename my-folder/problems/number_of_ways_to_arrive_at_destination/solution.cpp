class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (1e9 + 7);
        vector<pair<long, long>> adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long> dist(n,LONG_MAX);
        vector<long> ways(n,0);
        ways[0] = 1;
        dist[0] = 0;
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            long node = pq.top().second;
            long dis = pq.top().first;
            pq.pop();
            for(auto it : adj[node])
            {
                long time = it.second;
                long adjNode = it.first;
                if(dis + time < dist[adjNode])
                {
                    dist[adjNode] = dis + time;
                    pq.push({dis+time, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis+time == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};