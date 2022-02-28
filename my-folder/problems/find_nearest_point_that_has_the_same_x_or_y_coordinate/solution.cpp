class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int mini = INT_MAX;
        int ans = -1;
        for(int i = 0; i < points.size(); i++)
        {
            if(points[i][0] == x || points[i][1] == y)
            {
                int mDist = abs(x-points[i][0]) + abs(y-points[i][1]);
                if(mDist < mini)
                {
                    mini = mDist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};