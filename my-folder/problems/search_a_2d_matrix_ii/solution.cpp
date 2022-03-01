class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int r = n-1;
        if(r > n-1)
        {
            r = n-1;
            n = m;
        }
        cout<<m<<n;
        while(r >= 0 && l < m)
        {
            cout<<r<<l;
            if(matrix[r][l] == target)
                return true;
            if(matrix[r][l] < target)
                l++;
            else
                r--;
        }
        return false;
    }
};