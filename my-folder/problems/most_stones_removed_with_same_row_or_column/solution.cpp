
class DSU{
    private:
    vector<int> parent,size;
    public:
    DSU(int n){
        for(int i = 0; i <= n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    void unionSize(int a, int b){
        int pa = findPar(a);
        int pb = findPar(b);
        if(pa == pb){
            return;
        }
        if(size[pa] < size[pb]){
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        else{
            parent[pb] = pa;
            size[pa] += size[pb];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DSU dsu(maxRow + maxCol + 1);
        map<int, int> sn;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            dsu.unionSize(nodeRow, nodeCol);
            sn[nodeRow] = 1;
            sn[nodeCol] = 1;
        }

        int count = 0;
        for(auto it: sn){
            if(dsu.findPar(it.first) == it.first){
                count++;
            }
        }
        return n - count;
        
    }
};


