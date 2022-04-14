class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        int l = intervals[0][0];
        int r = intervals[0][1];
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] > r){
                vector<int> temp;
                temp.push_back(l);
                temp.push_back(r);
                v.push_back(temp);
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else{
                r = max(r, intervals[i][1]);
            }
        }
        vector<int> temp;
        temp.push_back(l);
        temp.push_back(r);
        v.push_back(temp);
        return v;
    }
};