class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> v;
        while(i < n && j < m){
            int i1 = max(firstList[i][0], secondList[j][0]);
            int i2 = min(firstList[i][1], secondList[j][1]);
            if(i1 <= i2)
                v.push_back({i1, i2});
            if(firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return v;
    }
};