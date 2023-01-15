class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<vector<int>> adjVer(vals.size());
        for(auto edge:edges){
            adjVer[edge[0]].push_back(edge[1]);
            adjVer[edge[1]].push_back(edge[0]);
        }

        map<int, vector<int>> valuesToNodes;
        for(int node=0;node<vals.size();node++)
            valuesToNodes[vals[node]].push_back(node);
        
        UnionFind dsu(vals.size());
        int goodPaths = 0;

        for(auto&[value,nodes]:valuesToNodes)
        {
            for(int node:nodes){
                for(int nextNode:adjVer[node]){
                    if(vals[node]>=vals[nextNode])
                        dsu.union_set(node,nextNode);
                }
            }

            unordered_map<int, int> group;

            for (int u : nodes)
                group[dsu.find(u)]++;
                
            for (auto& [_, size] : group)
                goodPaths += (size * (size + 1) / 2);
        }
        return goodPaths;
    }
};