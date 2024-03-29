class Solution {
public:

    vector < vector < int > > adj;
    string letters;

    int dfs(int u, int p, int& best_path){
        int best_path_1 = 0, best_path_2 = 0;
        
        auto update_max = [&](int x){
            if(x >= best_path_1)
                best_path_2 = best_path_1, best_path_1 = x;
            else if(x >= best_path_2)
                best_path_2 = x; 
        };

        for(auto& v : adj[u]){
            if(v == p) continue;
            int v_ans = dfs(v, u, best_path);
            if(letters[u] != letters[v])
                update_max(v_ans);
        }

        best_path = max({best_path, best_path_1 + best_path_2 + 1});

        return 1 + best_path_1;
    }

    void add_edge(int u, int v){
        adj[u].push_back(v), adj[v].push_back(u);
    }

    int longestPath(vector<int>& parent, string& s) {
        int n = parent.size();
        adj = vector < vector < int > > (n);
        letters = s;
        for(int i = 1; i < n; i++)
            add_edge(i, parent[i]);
        
        int best_path = 0;
        dfs(0, -1, best_path);

        return best_path;
    }
};