class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1)
            return 1;
        long long n = points.size() , ans=0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                long long temp_ans = 0;
                for(int k = 0; k < n; k++){
                    long long a=(points[k][1]-points[i][1])*(points[j][0]-points[i][0]);
                    long long b=(points[k][0]-points[i][0])*(points[j][1]-points[i][1]);
                    if(a == b)
                        temp_ans++;
                }
                ans = max(ans, temp_ans);
            }
        }    
        return ans;
    }
};