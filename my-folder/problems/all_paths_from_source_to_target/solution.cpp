class Solution {
public:

    void helper(vector<vector<int>>& graph, vector<vector<int>>& v, vector<int> temp, int src, int dest) {
        temp.push_back(src);
        if(src == dest) {
            v.push_back(temp);
            return;
        }

        for(auto it : graph[src])
            helper(graph, v, temp, it, dest);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> v;
        vector<int> temp;
        int size = graph.size();
        helper(graph, v, temp, 0, size - 1);
        return v;   
    }
};