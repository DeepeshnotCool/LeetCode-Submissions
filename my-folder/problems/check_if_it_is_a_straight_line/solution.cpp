class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(),coordinates.end());
        int m = coordinates.size();
        int n = coordinates[0].size();
        int dy = (coordinates[1][1] - coordinates[0][1]);
        int dx = (coordinates[1][0] - coordinates[0][0]);
        int slope;
        if(dx == 0)
            slope = 100000;
        else
            slope = dy/dx;
        for(int i = 1; i < m; i++)
        {
            int temp_dy = (coordinates[i][1] - coordinates[i-1][1]);
            int temp_dx = (coordinates[i][0] - coordinates[i-1][0]);        
            int temp_slope;
            if(temp_dx == 0)
                temp_slope = 100000;
            else 
                temp_slope = temp_dy/temp_dx;
            if(slope != temp_slope)
                return false;
        }
        return true;
    }
};















