class Solution {
public:
    int ans=INT_MAX;
    void helper(int node, vector<int> &visited, set<int> &st, unordered_map<int,vector<pair<int,int>>> &adj){

        for(auto it: adj[node]){
            if(!visited[it.first]){
                visited[it.first]=1;
                st.insert(it.first);
                helper(it.first, visited, st, adj);
                
            }
        }
        
        
    }
    int minScore(int n, vector<vector<int>>& roads) {
         unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
            
        }

        vector<int> visited(n+1,0);
        set<int> st;
        st.insert(1);
        helper(1, visited, st, adj);
        for(auto it: adj){
            if(st.find(it.first) != st.end()){
                for(auto it1: adj[it.first]){
                    ans = min(ans,it1.second);
                }
            }
        }
        
        return ans;
    }
};