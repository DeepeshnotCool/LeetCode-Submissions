const int maxn = 1e5+12;
long long output;
class Solution {
public:
    int st;
    vector<vector<int>> list_adj;
    vector<int> sub_tree;
    void dfs(int root,int parameter)
    {
        sub_tree[root]=1;
        for(auto x : list_adj[root])
             if(x!=parameter)
             {
                 dfs(x,root);
                 output += (sub_tree[x]+st-1)/st;
                 sub_tree[root] += sub_tree[x];
             }
    }
    long long minimumFuelCost(vector<vector<int>>& e, int available_seats) {
        int n=e.size()+1;
        output=0;
        st=available_seats;
        list_adj.assign(n+1,vector<int>());
        sub_tree.assign(n+1,0);
        for(auto x : e) 
        {
            list_adj[x[0]].push_back(x[1]);
            list_adj[x[1]].push_back(x[0]);
        }
        dfs(0,-1);
        return output; 
    }
};
