class Solution {
public:
    
    
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        for(int i = 0; i < mat.size(); i++){
            int countS = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1)
                    countS++;
                else
                    break;
            }
            v.push_back({i, countS});
        }
        stable_sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(int i = 0; i < k; i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
            ans.push_back(v[i].first);
        }
        return ans;
        
    }
};