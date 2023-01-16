class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];

        vector<vector<int>> ans;

        for(int i=0;i<intervals.size();i++){
            if(start >= intervals[i][0] & start <= intervals[i][1]){
                    start = intervals[i][0];
            }
            if(end >= intervals[i][0] && end <= intervals[i][1]){
                end = intervals[i][1];
            }
        }
        bool flag = false;
        if(intervals.size() == 0 || intervals[intervals.size()-1][1]<start){
            ans = intervals;
            ans.push_back(newInterval);
        }
        else
        for(int i=0;i<intervals.size();i++){

            if(intervals[i][1] < start){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][1] >= start && !flag){
                ans.push_back({start,end});
                flag = true;
                i--;
            }
            else if(intervals[i][0] > end){
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};