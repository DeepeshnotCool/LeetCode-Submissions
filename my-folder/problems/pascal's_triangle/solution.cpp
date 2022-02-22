class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> x(1,1);
        v.push_back(x);
        for(int i = 0; i < numRows-1; i++)
        {
            vector<int> temp;
            temp.push_back(v[0][0]);
            for(int j = 0; j < v[i].size()-1; j++)
            {
                int num = v[i][j] + v[i][j+1];
                temp.push_back(num);
            }
            int size = v[i].size()-1;
            temp.push_back(v[i][size]);
            v.push_back(temp);
        }
        return v;
    }
};