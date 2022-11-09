class Solution {
public:
    double distance(int x1, int y1){
        return  sqrt(pow((x1),2) + pow((y1),2));
    }

    static bool cmp(pair<vector<int>, double>& p1, pair<vector<int>, double>& p2){
        return p1.second < p2.second;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        double mini = 10000000;
        vector<pair<vector<int>, double>> v; 
        for(int i = 0; i < points.size(); i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            double dist = distance(x1, y1);
            v.push_back({points[i], dist});
        }

        sort(v.begin(), v.end(), cmp); 
        for(auto it: v){
            cout<<it.first[0]<<" "<<it.first[1]<<" "<<it.second<<endl;
        }
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};